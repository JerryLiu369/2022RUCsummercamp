#include "mytools.hpp"
#include <iostream>
#include<iomanip>
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    vector<int> map=my_stdinput().second;
    cout<<std::setw(2);
    for (size_t i = 0; i < WIDTH+2; i++)
    {
        for (size_t j = 0; j < LENGTH+2; j++)
        {
            cout<<map[xy2num(i,j)]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
