#include "mytools.hpp"
#include <map>
#include <iomanip>
#include <algorithm>
using std::map;
using std::random_shuffle;
using std::setw;
/*
决策思路：
A*寻路
用分数"亮度"评价增益
增长豆当成1分
蛇头附近一格减益
蛇头附近两格增益
护盾附近两格微弱增益
护盾立即使用，生效期间撞墙判定消失
*/
class Snake
{
private:
    pair<int, int> head{1, 1};
    vector<int> map_now = vector<int>((WIDTH + 2) * (LENGTH + 2), 0);

public:
    Snake(){};

    Snake(const pair<pair<int, int>, vector<int>> &stdinput)
    {
        head = stdinput.first;
        map_now = stdinput.second;
    }

    void show()
    {
        cout<<"head:"<<endl;
        cout<<head.first<<","<<head.second<<endl;
        cout<<"map:"<<endl;
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
        map<int, pair<int, int>> ref{{0, {0, -1}}, {1, {-1, 0}}, {2, {0, 1}}, {3, {1, 0}}};
        srand((unsigned)time(NULL));
        int movable=0;
        for (int j = 0; j < 4; j++)
        {
        pair<int, int> move = ref[j];
        if(map_now[xy2num(head.first + move.first, head.second + move.second)] != BLOCKED)movable=1;
        }
        if(movable==0)return rand()%4;
        while (true)
        {
        int i = rand()%4;
        pair<int, int> move = ref[i];
        if(map_now[xy2num(head.first + move.first, head.second + move.second)] != BLOCKED)
        {
            return i;
        }
        }
    }
};