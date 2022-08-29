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
    //整理成part
    int score = 0;
    vector<pair<int, vector<int>>> trans{};
    {
        int count_self;
        vector<int> now{};
        for (auto &&num : input_vec)
        {
            if (num == 1 - self)
            {
                if (!now.empty())
                {
                    trans.push_back({count_self, now});
                    now.clear();
                }
                continue;
            }
            else
            {
                if (num == self)
                    count_self++;
                now.push_back(num);
            }
        }
    }
    //
    for (auto &&part : trans)
    {
        //靠三个参数评分：part的长度，最大连子，自己子数
        int len = part.second.size();
        if (len < 5)
        {
            continue;
        }
        else if (len == 5)
        {
            if (part.first == 4)
                score += 1;
            else if (part.first == 5)
                score += 512;
        }
        else
        {
            int max_len = 0;
            {
                int temp_len = 0;
                for (auto &&i : part.second)
                {
                    if (i == self)
                        temp_len++;
                    else
                    {
                        if (temp_len > max_len)
                        {
                            max_len = temp_len;
                            temp_len = 0;
                        }
                    }
                }
            }
            if (max_len == 5)
                score += 1024;
            else if (max_len == 4)
            {
                if ((part.second[0] == -1 || part.second[1] == -1) && (part.second[len - 1] == -1 || part.second[len - 2] == -1))
                {
                    score += 4096;
                }
                else
                {
                    score += 128;
                    score += part.first - max_len;
                    score += len - max_len;
                }
            }
            else if (max_len == 3)
            {
                if (len > 6)
                    score += 1024;
                else
                    score += 10;
            }
            else if (max_len == 2)
            {
                score += 16;
            }
        }
    }
    //
    return score;
}

struct cmp
{
    bool operator()(const pair<float, int> &a, const pair<float, int> &b)
    {
        return a.first < b.first;
    }
};