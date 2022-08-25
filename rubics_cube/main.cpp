#include "cube.hpp"
#include <map>
#include <queue>
using std::cin;
using std::map;
using std::pair;
using std::queue;

/*
与作业输入输出的对应：
本魔方类初始化采用F,B,L,R,U,D
作业读入顺序则变成U,F,D,B,R,L   ,且B的朝向不同

动作的对应:
0+  l
1+  m
2+  r'
3+  b'
4+  s
5+  f
6+  d
7+  e
8+  u'
*/

void swap_int(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<vector<int>> input()
{
    map<char, int> color_dict{{'g', 0}, {'b', 1}, {'r', 2}, {'p', 3}, {'y', 4}, {'w', 5}};
    map<int, int> seq_dict{{0, 4}, {1, 0}, {2, 5}, {3, 1}, {4, 3}, {5, 2}};
    vector<vector<int>> init_vec(6, vector<int>(9, 0));
    for (size_t i = 0; i < 6; i++)
    {
        char converter;
        vector<int> temp(9, 0);
        for (size_t j = 0; j < 9; j++)
        {
            cin >> converter;
            temp[j] = color_dict[converter];
        }
        if (i == 3)
        {
            swap_int(temp[0], temp[6]);
            swap_int(temp[1], temp[7]);
            swap_int(temp[2], temp[8]);
        }
        init_vec[seq_dict[i]] = temp;
    }
    return init_vec;
}

int main()
{
    Cube origin(input());
    origin.show_shape();
    vector<int> options{0, 1, 2, 3, 4, 5, 6, 7, 8, -1, -2, -3, -4, -5, -6, -7, -8, -9};
    map<int, pair<char, bool>> trans{{0, pair<char, bool>{'l', false}},
                                     {1, pair<char, bool>{'m', false}},
                                     {2, pair<char, bool>{'r', true}},
                                     {3, pair<char, bool>{'b', true}},
                                     {4, pair<char, bool>{'s', false}},
                                     {5, pair<char, bool>{'f', false}},
                                     {6, pair<char, bool>{'d', false}},
                                     {7, pair<char, bool>{'e', false}},
                                     {8, pair<char, bool>{'u', true}},
                                     {-1, pair<char, bool>{'l', true}},
                                     {-2, pair<char, bool>{'m', true}},
                                     {-3, pair<char, bool>{'r', false}},
                                     {-4, pair<char, bool>{'b', false}},
                                     {-5, pair<char, bool>{'s', true}},
                                     {-6, pair<char, bool>{'f', true}},
                                     {-7, pair<char, bool>{'d', true}},
                                     {-8, pair<char, bool>{'e', true}},
                                     {-9, pair<char, bool>{'u', false}}};
    queue<pair<Cube, vector<int>>> se_q;
    se_q.push({origin, {}});
    vector<int> res{};
    int flag = 0;
    if (origin.is_fine())
    {
        flag = 1;
    }
    int count = 0;
    while (true)
    {
        if (flag == 1)
        {
            break;
        }
        pair<Cube, vector<int>> now(se_q.front());
        se_q.pop();
        for (int i = -9; i < 9; i++)
        {
            if (now.second.size() != 0 && i + now.second[now.second.size() - 1] == -1)
            {
                continue;
            }
            Cube temp_cube = now.first;
            temp_cube.rotate(trans[i]);
            if (temp_cube.is_fine())
            {
                flag = 1;
                vector<int> temp_vec = now.second;
                temp_vec.emplace_back(i);
                res=temp_vec;
                break;
            }
            vector<int> temp_vec = now.second;
            temp_vec.emplace_back(i);
            se_q.push({temp_cube, temp_vec});
            if (count % 10000 == 0)
                cout << count << endl;
            count++;
        }
    }
    cout << "done!" << endl;
    for (auto &&i : res)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
