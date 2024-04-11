#include <iostream>
#include "GF.cpp"
int main () {

    GF first(11, 8);
    GF second(11, 2);

    //GF third = first+second;
    //std::cout<<third.getValue()<<std::endl;

    GF third = first+second;
    std::cout<<third<<std::endl;

    third = first-second;
    std::cout<<third.getValue()<<std::endl;

    third = first*second;
    std::cout<<third.getValue()<<std::endl;

    third = first/second;
    std::cout<<third.getValue()<<std::endl;

    third = first;
    third+=second;
    std::cout<<third.getValue()<<std::endl;

    third = first;
    third-=second;
    std::cout<<third.getValue()<<std::endl;

    third = first;
    third*=second;
    std::cout<<third.getValue()<<std::endl;

    third = first;
    third/=second;
    std::cout<<third.getValue()<<std::endl;

    third << -15;
    std::cout<<third<<std::endl;

    //  third = first*second;
   // std::cout<<third.getValue()<<std::endl;

   // third = first/second;
   // std::cout<<third.getValue()<<std::endl;
    //std::cout<<lala.x<<" "<<lala.y<<" "<<lala.d<<std::endl;
}
