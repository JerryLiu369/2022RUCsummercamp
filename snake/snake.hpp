#include "mytools.hpp"
#include <vector>
using std::vector;
/*
决策思路：
A*寻路
用分数"亮度"评价增益
增长豆当成1分
蛇头附近一格减益
蛇头附近两格增益
护盾附近两格微弱增益
护盾立即使用，生效期间撞墙判定消失
*/
class Snake
{
private:
    vector<int> map;
    vector<int> head{1,1};
public:
    Snake(/* args */);
    ~Snake();
};

Snake::Snake(/* args */)
{
}

Snake::~Snake()
{
}
