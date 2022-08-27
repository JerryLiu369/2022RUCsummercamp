#include "snake.hpp"
int main()
{
    Snake mysnake(my_stdinput());
    mysnake.show();
    cout << mysnake.decide() << endl;
    return 0;
}
