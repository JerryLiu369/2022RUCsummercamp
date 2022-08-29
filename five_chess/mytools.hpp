#include <vector>
#include <iostream>
using std::cin;
using std::pair;
using std::vector;
int WIDTH = 15;

inline int xy2num(const int &x, const int &y)
{
    return x + WIDTH * y;
}

pair<int, vector<int>> my_input()
{
    int self;
    cin >> self;
    vector<int> situation_input(WIDTH * WIDTH, 0);
    for (int i = 0; i < WIDTH * WIDTH; i++)
    {
        cin >> situation_input[i];
    }
    return pair<int, vector<int>>{self, situation_input};
}

inline int value_vector(const int &self, const vector<int> &input_vec)
{
    vector<pair<int,int>> trans{};
    int front=1;
    vector<int> now{};
    int counter;
    for (auto &&num : input_vec)
    {
        if (num==1-self)
        {
            if (now.empty())
            {
                continue;
            }
            else
            {
                now.clear();
                continue;
            }
        }
    }
}
