# main.cpp
主函数

调用Snake类，传入`mystdinput()`获取的盘面进行初始化，`decide()`方法决策，然后输出

# mytools.hpp
主要实现了输入获取函数，以及一些代码段

# snake.hpp
实现了Snake类

`find_destination()`方法对蛇头附近10*10的区域逐格执行`value_point()`方法，找到价值最高目标，`find_way()`使用A\*算法寻路