#include <vector>
#include <iostream>
using std::cin;
using std::pair;
using std::vector;
int TOTAL_TIME = 240;
int LENGTH = 40;
int WIDTH = 30;
int BLOCKED = -3;
int MY_ID = 2021201247;
/*
地图表示的规定：
0   空格子
-4   障碍物格子
1,2,3,5... 不同分数的豆子
-1  增长豆
-2  盾牌
-3  自己蛇头
-4  其他蛇身
-5  其他蛇头
*/
inline int xy2num(int x, int y)
{
    return x * (LENGTH + 2) + y;
}

inline vector<int> num2xy(int num)
{
    return vector<int>{num / (LENGTH + 2), num % (LENGTH + 2)};
}

pair<int, vector<int>> my_stdinput()
{
    vector<int> map((WIDTH + 2) * (LENGTH + 2), 0);
    for (size_t i = 0; i < WIDTH + 2; i++)
    {
        if (i == 0 || i == WIDTH + 1)
        {
            for (size_t j = 0; j < LENGTH + 2; j++)
            {
                map[xy2num(i, j)] = BLOCKED;
            }
        }
        else
        {
            map[xy2num(i, 0)] = BLOCKED;
            map[xy2num(i, LENGTH + 1)] = BLOCKED;
        }
    }
    int time = 0;
    cin >> time;
    time = TOTAL_TIME - time;
    int __count_bonus;
    cin >> __count_bonus;
    for (size_t i = 0; i < __count_bonus; i++)
    {
        int x, y, code;
        cin >> x >> y >> code;
        map[xy2num(x + 1, y + 1)] = code;
    }
    int __count_barrier;
    cin >> __count_barrier;
    for (size_t i = 0; i < __count_barrier; i++)
    {
        int x,y,radius,last_time;
        cin>>x>>y>>radius>>last_time;
        for (int distance = 0; distance <= radius+1; distance++)
        {
            for (size_t i = 0; i <= distance; i++)
            {
                for (size_t j = 0; j <= distance-i; j++)
                {
                    map[xy2num(x+1+i,y+1+j)]=-4;
                    map[xy2num(x+1-i,y+1+j)]=-4;
                    map[xy2num(x+1+i,y+1-j)]=-4;
                    map[xy2num(x+1-i,y+1-j)]=-4;
                }
            }
        }
    }
    return pair<int, vector<int>>{time, map};
}