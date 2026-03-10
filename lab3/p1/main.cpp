#include <iostream>
#include <cstdlib>
#include "Math.h"
int main () {
    std::cout<<Math::Add(2 , 3)<<'\n';
    std::cout<<Math::Add(2 , 3 , 5)<<'\n';
    std::cout<<Math::Add(2.5 , 3.5)<<'\n';
    std::cout<<Math::Add(2.5 , 3.5 , 4.0)<<'\n';
    std::cout<<Math::Mul(4 , 5)<<'\n';
    std::cout<<Math::Mul(4 , 5 , 6)<<'\n';
    std::cout<<Math::Mul(4.0 , 5.5)<<'\n';
    std::cout<<Math::Mul(4.0 , 5.0 , 5.5)<<'\n';
    std::cout<<Math::Add(5 , 1 , 2 , 3 , 4 , 5)<<'\n';
    std::cout<<Math::Add("Hello " , "World");
    return 0;
}