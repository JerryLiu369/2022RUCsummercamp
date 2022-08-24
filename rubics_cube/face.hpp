#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
class Face
{
private:
    vector<int> data = vector<int>(9, 0);

public:
    Face()
    {
        data = vector<int>(9, 0);
    }

    Face(const int &num)
    {
        data = vector<int>(9, num);
    }

    Face(const vector<int> &data):data(data){}

    ~Face()
    {
        data.clear();
    }

    void show()
    {
        cout << data[0] << " " << data[1] << " " << data[2] << endl;
        cout << data[3] << " " << data[4] << " " << data[5] << endl;
        cout << data[6] << " " << data[7] << " " << data[8] << endl;
    }
    void show_first()
    {
        cout << data[0] << " " << data[1] << " " << data[2] << " ";
    }
    void show_second()
    {
        cout << data[3] << " " << data[4] << " " << data[5] << " ";
    }
    void show_third()
    {
        cout << data[6] << " " << data[7] << " " << data[8] << " ";
    }

    inline void rotate()
    {
        int temp = data[3];
        data[3] = data[6];
        data[6] = data[7];
        data[7] = data[8];
        data[8] = data[5];
        data[5] = data[2];
        data[2] = data[1];
        data[1] = data[0];
        data[0] = temp;
    }
    inline void rotate_re()
    {
        int temp = data[0];
        data[0] = data[1];
        data[1] = data[2];
        data[2] = data[5];
        data[5] = data[8];
        data[8] = data[7];
        data[7] = data[6];
        data[6] = data[3];
        data[3] = temp;
    }
    
    bool is_num(const int &num)
    {
        for (auto &&i : data)
        {
            if (i != num)
            {
                return false;
            }
        }
        return true;
    }

    inline vector<int> left()
    {
        return vector<int>{data[0], data[3], data[6]};
    } // 0,3,6
    inline vector<int> vertical()
    {
        return vector<int>{data[1], data[4], data[7]};
    } // 1,4,7
    inline vector<int> right()
    {
        return vector<int>{data[2], data[5], data[8]};
    } // 2,5,8
    inline vector<int> up()
    {
        return vector<int>{data[0], data[1], data[2]};
    } // 0,1,2
    inline vector<int> horizental()
    {
        return vector<int>{data[3], data[4], data[5]};
    } // 3,4,5
    inline vector<int> down()
    {
        return vector<int>{data[6], data[7], data[8]};
    } // 6,7,8

    inline void set_left(const vector<int> &vec)
    {
        data[0] = vec[0];
        data[3] = vec[1];
        data[6] = vec[2];
    }
    inline void set_vertical(const vector<int> &vec)
    {
        data[1] = vec[0];
        data[4] = vec[1];
        data[7] = vec[2];
    }
    inline void set_right(const vector<int> &vec)
    {
        data[2] = vec[0];
        data[5] = vec[1];
        data[8] = vec[2];
    }
    inline void set_up(const vector<int> &vec)
    {
        data[0] = vec[0];
        data[1] = vec[1];
        data[2] = vec[2];
    }
    inline void set_horizental(const vector<int> &vec)
    {
        data[3] = vec[0];
        data[4] = vec[1];
        data[5] = vec[2];
    }
    inline void set_down(const vector<int> &vec)
    {
        data[6] = vec[0];
        data[7] = vec[1];
        data[8] = vec[2];
    }
};

static inline vector<int> vec_reverse(const vector<int> &vec)
{
    return vector<int>{vec[2], vec[1], vec[0]};
}