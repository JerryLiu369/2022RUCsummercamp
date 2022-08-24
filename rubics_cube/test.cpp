#include"cube.hpp"
int main(){
    Cube a;
    cout<<a.is_fine()<<endl;
    a.show_shape();
    a.rotate('f',false);
    cout<<a.is_fine()<<endl;
    a.show_shape();
}