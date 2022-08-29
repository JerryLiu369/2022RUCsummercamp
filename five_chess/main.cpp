#include "situation.hpp"
using std::cout;

int main()
{
    Situation now(my_input());
    pair<int, int> res = now.decide();
    cout << res.first << " " << res.second;
    return 0;
}