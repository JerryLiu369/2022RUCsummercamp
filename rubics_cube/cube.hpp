#include "face.hpp"
using std::pair;
class Cube
{
    /*
    F=0
    B=1
    L=2
    R=3
    U=4
    D=5
    方向规定：
        从初始状态整体反转一次的朝向，即做一次x/y/z(或')。对于B，为做x2的朝向
        即以下图展开的朝向：
            B1
            U4
        L2  F0  R3
            D5
    */
private:
    Face F, B, L, R, U, D;

public:
    Cube()
    {
        F = Face(0);
        B = Face(1);
        L = Face(2);
        R = Face(3);
        U = Face(4);
        D = Face(5);
    }

    Cube(const vector<vector<int>> &color)
    {
        if (color.size() == 6 && color[0].size() == 9)
        {
            F = Face(color[0]);
            B = Face(color[1]);
            L = Face(color[2]);
            R = Face(color[3]);
            U = Face(color[4]);
            D = Face(color[5]);
        }
        else
            throw -1;
    }

    void reset()
    {
        F = Face(0);
        B = Face(1);
        L = Face(2);
        R = Face(3);
        U = Face(4);
        D = Face(5);
    }

    void show()
    {
        cout << "F:" << endl;
        F.show();
        cout << "B:" << endl;
        B.show();
        cout << "L:" << endl;
        L.show();
        cout << "R:" << endl;
        R.show();
        cout << "U:" << endl;
        U.show();
        cout << "D:" << endl;
        D.show();
    }

    void show_shape()
    {
        cout << endl;
        cout << "      ";
        B.show_first();
        cout << endl;
        cout << "      ";
        B.show_second();
        cout << endl;
        cout << "      ";
        B.show_third();
        cout << endl;
        //
        cout << "      ";
        U.show_first();
        cout << endl;
        cout << "      ";
        U.show_second();
        cout << endl;
        cout << "      ";
        U.show_third();
        cout << endl;
        //
        L.show_first();
        F.show_first();
        R.show_first();
        cout << endl;
        L.show_second();
        F.show_second();
        R.show_second();
        cout << endl;
        L.show_third();
        F.show_third();
        R.show_third();
        cout << endl;
        //
        cout << "      ";
        D.show_first();
        cout << endl;
        cout << "      ";
        D.show_second();
        cout << endl;
        cout << "      ";
        D.show_third();
        cout << endl;
        cout << endl;
    }

    inline bool is_fine()
    {
        return F.is_same() && B.is_same() && L.is_same() && R.is_same() && U.is_same() && D.is_same();
    }

    inline void rotate(const char &option, bool reverse)
    {
        if (option == 'f' || option == 'F')
        {
            if (reverse)
            {
                F.rotate_re();
                vector<int> temp(3, 0);
                temp = U.down();
                U.set_down(R.left());
                R.set_left(vec_reverse(D.up()));
                D.set_up(L.right());
                L.set_right(vec_reverse(temp));
            }
            else
            {
                F.rotate();
                vector<int> temp(3, 0);
                temp = L.right();
                L.set_right(D.up());
                D.set_up(vec_reverse(R.left()));
                R.set_left(U.down());
                U.set_down(vec_reverse(temp));
            }
        }
        else if (option == 'b' || option == 'B')
        {
            if (reverse)
            {
                B.rotate_re();
                vector<int> temp(3, 0);
                temp = L.left();
                L.set_left(D.down());
                D.set_down(vec_reverse(R.right()));
                R.set_right(U.up());
                U.set_up(vec_reverse(temp));
            }
            else
            {
                B.rotate();
                vector<int> temp(3, 0);
                temp = U.up();
                U.set_up(R.right());
                R.set_right(vec_reverse(D.down()));
                D.set_down(L.left());
                L.set_left(vec_reverse(temp));
            }
        }
        else if (option == 's' || option == 'S')
        {
            if (reverse)
            {
                vector<int> temp(3, 0);
                temp = U.horizontal();
                U.set_horizontal(R.vertical());
                R.set_vertical(vec_reverse(D.horizontal()));
                D.set_horizontal(L.vertical());
                L.set_vertical(vec_reverse(temp));
            }
            else
            {
                vector<int> temp(3, 0);
                temp = L.vertical();
                L.set_vertical(D.horizontal());
                D.set_horizontal(vec_reverse(R.vertical()));
                R.set_vertical(U.horizontal());
                U.set_horizontal(vec_reverse(temp));
            }
        }
        else if (option == 'l' || option == 'L')
        {
            if (reverse)
            {
                L.rotate_re();
                vector<int> temp(3, 0);
                temp = B.left();
                B.set_left(U.left());
                U.set_left(F.left());
                F.set_left(D.left());
                D.set_left(temp);
            }
            else
            {
                L.rotate();
                vector<int> temp(3, 0);
                temp = D.left();
                D.set_left(F.left());
                F.set_left(U.left());
                U.set_left(B.left());
                B.set_left(temp);
            }
        }
        else if (option == 'r' || option == 'R')
        {
            if (reverse)
            {
                R.rotate_re();
                vector<int> temp(3, 0);
                temp = D.right();
                D.set_right(F.right());
                F.set_right(U.right());
                U.set_right(B.right());
                B.set_right(temp);
            }
            else
            {
                R.rotate();
                vector<int> temp(3, 0);
                temp = B.right();
                B.set_right(U.right());
                U.set_right(F.right());
                F.set_right(D.right());
                D.set_right(temp);
            }
        }
        else if (option == 'm' || option == 'M')
        {
            if (reverse)
            {
                vector<int> temp(3, 0);
                temp = B.vertical();
                B.set_vertical(U.vertical());
                U.set_vertical(F.vertical());
                F.set_vertical(D.vertical());
                D.set_vertical(temp);
            }
            else
            {
                vector<int> temp(3, 0);
                temp = D.vertical();
                D.set_vertical(F.vertical());
                F.set_vertical(U.vertical());
                U.set_vertical(B.vertical());
                B.set_vertical(temp);
            }
        }
        else if (option == 'u' || option == 'U')
        {
            if (reverse)
            {
                U.rotate_re();
                vector<int> temp(3, 0);
                temp = R.up();
                R.set_up(F.up());
                F.set_up(L.up());
                L.set_up(vec_reverse(B.down()));
                B.set_down(vec_reverse(temp));
            }
            else
            {
                U.rotate();
                vector<int> temp(3, 0);
                temp = B.down();
                B.set_down(vec_reverse(L.up()));
                L.set_up(F.up());
                F.set_up(R.up());
                R.set_up(vec_reverse(temp));
            }
        }
        else if (option == 'd' || option == 'D')
        {
            if (reverse)
            {
                D.rotate_re();
                vector<int> temp(3, 0);
                temp = B.up();
                B.set_up(vec_reverse(L.down()));
                L.set_down(F.down());
                F.set_down(R.down());
                R.set_down(vec_reverse(temp));
            }
            else
            {
                D.rotate();
                vector<int> temp(3, 0);
                temp = R.down();
                R.set_down(F.down());
                F.set_down(L.down());
                L.set_down(vec_reverse(B.up()));
                B.set_up(vec_reverse(temp));
            }
        }
        else if (option == 'e' || option == 'E')
        {
            if (reverse)
            {
                vector<int> temp(3, 0);
                temp = B.horizontal();
                B.set_horizontal(vec_reverse(L.horizontal()));
                L.set_horizontal(F.horizontal());
                F.set_horizontal(R.horizontal());
                R.set_horizontal(vec_reverse(temp));
            }
            else
            {
                vector<int> temp(3, 0);
                temp = R.horizontal();
                R.set_horizontal(F.horizontal());
                F.set_horizontal(L.horizontal());
                L.set_horizontal(vec_reverse(B.horizontal()));
                B.set_horizontal(vec_reverse(temp));
            }
        }
        else
        {
            cout << "Wrong Operation!" << endl;
            throw -1;
        }
    }

    inline void rotate(pair<char, bool> option)
    {
        rotate(option.first, option.second);
    }
};
