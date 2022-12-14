#include "valuedpoint.hpp"
#include <map>
#include <iomanip>
#include <algorithm>
#include <queue>
using std::map;
using std::priority_queue;
using std::random_shuffle;
using std::setw;
/*
决策思路：
A*寻路
用分数"亮度"评价增益
增长豆当成1分
蛇头附近一格减益
蛇头附近两格增益
# 护盾附近两格微弱增益
# 护盾立即使用，生效期间撞墙判定消失
*/

class Snake
{
private:
    pair<int, int> head{1, 1};
    pair<int, int> sub_head{1, 1};
    vector<int> map_now = vector<int>((WIDTH + 2) * (LENGTH + 2), 0);

public:
    Snake(){};

    Snake(const pair<pair<pair<int, int>, pair<int, int>>, vector<int>> &stdinput)
    {
        head = stdinput.first.first;
        sub_head = stdinput.first.second;
        map_now = stdinput.second;
    }

    void show()
    {
        cout << "head:" << endl;
        cout << head.first << "," << head.second << endl;
        cout << "map:" << endl;
        for (int i = 0; i < WIDTH + 2; i++)
        {
            for (int j = 0; j < LENGTH + 2; j++)
            {
                cout << std::setw(3) << map_now[xy2num(i, j)];
            }
            cout << endl;
        }
    }

    int decide()
    {
        map<int, pair<int, int>> move_ref{{0, {0, -1}}, {1, {-1, 0}}, {2, {0, 1}}, {3, {1, 0}}};
        vector<int> movable;
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> move = move_ref[i];
            if (map_now[xy2num(head.first + move.first, head.second + move.second)] != BLOCKED && (!(head.first + move.first == sub_head.first && head.second + move.second == sub_head.second)))
            {
                movable.push_back(i);
            }
            if (map_now[xy2num(head.first + move.first, head.second + move.second)] > 0)
                return i;
        }
        pair<int, int> destination = find_destination();
        return find_way(movable, destination);
        srand((unsigned)time(NULL));
        return rand() % 4;
    }

    pair<int, int> find_destination()
    {
        priority_queue<ValuedPoint, vector<ValuedPoint>> choose_queue;
        for (int i = -5; i <= 5; i++)
        {
            for (int j = -5; j <= 5; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                pair<int, int> temp_point{head.first + i, head.second + j};
                if (is_overflow(temp_point))
                {
                    continue;
                }
                choose_queue.push(ValuedPoint(value_point(temp_point), temp_point));
            }
        }
        ValuedPoint choice = choose_queue.top();
        return choice.get_point();
    }

    float value_point(const pair<int, int> &point)
    {
        int count_block = 0;
        float score = 0;
        for (int i = -2; i <= 2; i++)
        {
            for (int j = -2; j <= 2; j++)
            {
                if (is_overflow(pair<int, int>{point.first + i, point.second + j}))
                {
                    continue;
                }
                count_block++;
                int this_point = map_now[xy2num(point.first + i, point.second + j)];
                if (this_point > 0)
                    score += ((rand()%2+9)/10.0)*this_point;
                else if (this_point == BLOCKED)
                    score -= 1;
                else if ((this_point == -4) && ((abs(i) == 1) || (abs(j) == 1)))
                    score -= 5;
                else if (this_point == -2)
                    score += 0;
                else if (this_point == -1)
                    score += 1;
            }
        }
        score-=0.4*(abs(point.first-head.first)+abs(point.second-head.second));
        score-=0.2*(abs(point.first-WIDTH/2)+abs(point.second-LENGTH/2));
        if (count_block == 0)
            return 0;
        return score / count_block;
    }

    int find_way(const vector<int> &movable, const pair<int, int> &destination)
    {
        map<int, pair<int, int>> move_ref{{0, {0, -1}}, {1, {-1, 0}}, {2, {0, 1}}, {3, {1, 0}}};
        vector<int> distances;
        for (auto &&way : movable)
        {
            pair<int, int> move = move_ref[way];
            distances.push_back(abs(head.first + move.first - destination.first) + abs(head.second + move.second - destination.second));
        }
        int min_dis = LENGTH + WIDTH;
        int position;
        for (int i = 0; i < int(movable.size()); i++)
        {
            if (distances[i] < min_dis)
            {
                min_dis = distances[i];
                position = i;
            }
        }
        return movable[position];
    }

    inline bool is_overflow(const pair<int, int> &point)
    {
        return (point.first < 1) || (point.first > WIDTH) || (point.second < 1) || (point.second > LENGTH);
    }
};