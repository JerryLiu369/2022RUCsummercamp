#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
int TOTAL_TIME = 250;
int LENGTH = 40;
int WIDTH = 30;
int BLOCKED = -5;
int MY_ID = 2021201247;
/*
地图表示的规定：
0   空格子
-5   障碍物格子
1,2,3,5... 不同分数的豆子
-1  增长豆
-2  盾牌
-3  自己蛇头
-4  其他蛇头
-5  其他蛇身
*/
inline int xy2num(int x, int y)
{
    return x * (LENGTH + 2) + y;
}

inline vector<int> num2xy(int num)
{
    return vector<int>{num / (LENGTH + 2), num % (LENGTH + 2)};
}

pair<pair<int, int>, vector<int>> my_stdinput()
{
    pair<int, int> head{0, 0};
    vector<int> map_input((WIDTH + 2) * (LENGTH + 2), 0);
    for (int i = 0; i < WIDTH + 2; i++)
    {
        if (i == 0 || i == WIDTH + 1)
        {
            for (int j = 0; j < LENGTH + 2; j++)
            {
                map_input[xy2num(i, j)] = BLOCKED;
            }
        }
        else
        {
            map_input[xy2num(i, 0)] = BLOCKED;
            map_input[xy2num(i, LENGTH + 1)] = BLOCKED;
        }
    }
    int time = 0;
    cin >> time;
    time = TOTAL_TIME - time;
    int __count_bonus;
    cin >> __count_bonus;
    for (int i = 0; i < __count_bonus; i++)
    {
        int x, y, code;
        cin >> x >> y >> code;
        map_input[xy2num(x + 1, y + 1)] = code;
    }
    int __count_barrier;
    cin >> __count_barrier;
    for (int i = 0; i < __count_barrier; i++)
    {
        int x, y, radius, last_time;
        cin >> x >> y >> radius >> last_time;
        for (int distance = 0; distance <= radius + 1; distance++)
        {
            for (int i = 0; i <= distance; i++)
            {
                for (int j = 0; j <= distance - i; j++)
                {
                    map_input[xy2num(x + 1 + i, y + 1 + j)] = BLOCKED;
                    map_input[xy2num(x + 1 - i, y + 1 + j)] = BLOCKED;
                    map_input[xy2num(x + 1 + i, y + 1 - j)] = BLOCKED;
                    map_input[xy2num(x + 1 - i, y + 1 - j)] = BLOCKED;
                }
            }
        }
    }
    int __count_player;
    cin >> __count_player;
    for (int i = 0; i < __count_player; i++)
    {
        int id, len, score, direction, shield_num, shield_time;
        cin >> id >> len >> score >> direction >> shield_num >> shield_time;
        int x, y;
        cin >> x >> y;
        if (id == MY_ID)
        {
            map_input[xy2num(x + 1, y + 1)] = -3;
            head = pair<int, int>{x + 1, y + 1};
            for (int j = 0; j < len - 1; j++)
            {
                cin >> x >> y;
            }
        }
        else
        {
            map_input[xy2num(x + 1, y + 1)] = -4;
            for (int j = 0; j < len - 1; j++)
            {
                cin >> x >> y;
                map_input[xy2num(x + 1, y + 1)] = BLOCKED;
            }
        }
    }
    return pair<pair<int, int>, vector<int>>{head, map_input};
}