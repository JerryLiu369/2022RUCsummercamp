#include "mytools.hpp"

class Situation
{
private:
    int self;
    vector<int> data;

public:
    Situation(const pair<int, vector<int>> my_input)
    {
        self = my_input.first;
        data = my_input.second;
    }

    pair<int, int> decide()
    {
    }

    float value_situation(const int &depth_now, const int &depth_set) const
    {
        float score = 0;
        for (int i = 0; i < WIDTH; i++)
        {
            vector<int> temp_vec(WIDTH, 0);
            for (int j = 0; j < WIDTH; j++)
            {
                temp_vec[j] = data[xy2num(i, j)];
            }
            score += value_vector(self, temp_vec);
        }

        for (int j = 0; j < WIDTH; j++)
        {
            vector<int> temp_vec(WIDTH, 0);
            for (int i = 0; i < WIDTH; i++)
            {
                temp_vec[i] = data[xy2num(i, j)];
            }
            score += value_vector(self, temp_vec);
        }

        {
            vector<int> temp_vec1(WIDTH, 0);
            vector<int> temp_vec2(WIDTH, 0);
            for (int i = 0; i < WIDTH; i++)
            {
                temp_vec1[i] = data[xy2num(i, i)];
                temp_vec2[i] = data[xy2num(i, WIDTH - 1 - i)];
            }
            score += value_vector(self, temp_vec1);
            score += value_vector(self, temp_vec2);
        }

        for (int diff = 0; diff <= WIDTH - 5; diff++)
        {
            vector<int> temp_vec1(WIDTH - diff, 0);
            vector<int> temp_vec2(WIDTH - diff, 0);
            vector<int> temp_vec3(WIDTH - diff, 0);
            vector<int> temp_vec4(WIDTH - diff, 0);
            for (int i = 0; i < WIDTH - diff; i++)
            {
                temp_vec1[i] = data[xy2num(i, i + diff)];
                temp_vec2[i] = data[xy2num(i + diff, i)];
                temp_vec3[i] = data[xy2num(i, WIDTH - 1 - diff - i)];
                temp_vec4[i] = data[xy2num(WIDTH - 1 - i, diff + i)];
            }
            score += value_vector(self, temp_vec1);
            score += value_vector(self, temp_vec2);
            score += value_vector(self, temp_vec3);
            score += value_vector(self, temp_vec4);
        }

        return score;
    }
};