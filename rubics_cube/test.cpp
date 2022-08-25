#include"cube.hpp"
void test_cube()
{
    Cube a({{1,0,4,1,1,1,1,3,3},{2,4,1,4,4,1,3,5,3},{5,0,5,2,0,4,0,2,2},{5,5,0,5,5,0,2,3,3},{1,5,4,2,3,3,4,4,0},{5,4,0,2,2,0,4,3,2}});
    a.rotate('r',false);
    a.rotate('r',true);
    a.rotate('u',false);
    a.rotate('u',true);
    a.rotate('f',false);
    a.rotate('f',true);
    a.rotate('l',false);
    a.rotate('l',true);
    a.rotate('d',false);
    a.rotate('d',true);
    a.rotate('b',false);
    a.rotate('b',true);
    a.rotate('m',false);
    a.rotate('m',true);
    a.rotate('e',false);
    a.rotate('e',true);
    a.rotate('s',false);
    a.rotate('s',true);
    a.show_shape();
}

void test_face()
{
    vector<int> vec{0,0,0,1,1,1,0,0,0};
    Face a(vec);
    a.rotate();
    a.show();
}

int main(){
    test_cube();
}