#include "snake.hpp"
int main()
{
    srand((unsigned)time(NULL));
    Snake mysnake(my_stdinput());
    cout << mysnake.decide();
    return 0;
}
