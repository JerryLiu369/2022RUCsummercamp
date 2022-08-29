#include "mytools.hpp"
#include <set>
#include <queue>
using std::priority_queue;
using std::set;

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

    Situation(const int &self, const vector<int> &data) : self(self), data(data){};

    pair<int, int> decide()
    {
        priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> choose_queue;
        set<int> movable = find_movable();
        if (movable.empty())
            return {WIDTH / 2, WIDTH / 2};
        for (auto &&move : find_movable())
        {
            vector<int> data_copy(data);
            data_copy[move] = self;
            Situation temp_situation(self, data_copy);
            choose_queue.push({temp_situation.value_situation(1, 3), move});
        }
        int move = choose_queue.top().second;
        return {move / WIDTH, move % WIDTH};
    }

    float value_situation(const int &depth_now, const int &depth_set) const
    {
        int score_now = 0;
        for (int i = 0; i < WIDTH; i++)
        {
            vector<int> temp_vec(WIDTH, 0);
            for (int j = 0; j < WIDTH; j++)
            {
                temp_vec[j] = data[xy2num(i, j)];
            }
            score_now += value_vector(self, temp_vec);
        }

        for (int j = 0; j < WIDTH; j++)
        {
            vector<int> temp_vec(WIDTH, 0);
            for (int i = 0; i < WIDTH; i++)
            {
                temp_vec[i] = data[xy2num(i, j)];
            }
            score_now += value_vector(self, temp_vec);
        }

        {
            vector<int> temp_vec1(WIDTH, 0);
            vector<int> temp_vec2(WIDTH, 0);
            for (int i = 0; i < WIDTH; i++)
            {
                temp_vec1[i] = data[xy2num(i, i)];
                temp_vec2[i] = data[xy2num(i, WIDTH - 1 - i)];
            }
            score_now += value_vector(self, temp_vec1);
            score_now += value_vector(self, temp_vec2);
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
            score_now += value_vector(self, temp_vec1);
            score_now += value_vector(self, temp_vec2);
            score_now += value_vector(self, temp_vec3);
            score_now += value_vector(self, temp_vec4);
        }

        if (depth_now == depth_set)
            return score_now;
        else
        {
            priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> choose_queue;
            for (auto &&move : find_movable())
            {
                vector<int> data_copy(data);
                data_copy[move] = self;
                Situation temp_situation(1 - self, data_copy);
                choose_queue.push({temp_situation.value_situation(0, 0), move});
            }
            int count_total = 0;
            float score_total = 0;
            for (int i = 0; i < std::min(int(choose_queue.size()), 10); i++)
            {
                count_total++;
                int move = choose_queue.top().second;
                choose_queue.pop();
                vector<int> data_copy(data);
                data_copy[move] = self;
                Situation temp_situation(1 - self, data_copy);
                score_total += temp_situation.value_situation(depth_now + 1, depth_set);
            }
            if (count_total == 0)
                return 0;
            return score_now - score_total / count_total;
        }
    }

    set<int> find_movable() const
    {
        set<int> movable;
        vector<int> chooses{-WIDTH, -1, 1, WIDTH};
        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                int index = xy2num(i, j);
                if (data[index] == -1)
                {
                    for (auto &&choose : chooses)
                    {
                        if (index + choose < 0 || index + choose >= WIDTH * WIDTH)
                        {
                            continue;
                        }
                        else
                        {
                            if (data[index + choose] != -1)
                            {
                                movable.insert(index);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return movable;
    }
};