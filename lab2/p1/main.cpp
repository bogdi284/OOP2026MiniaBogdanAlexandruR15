#include <iostream>

#include "NumberList.h"
int main () {
    NumberList n ;
    n.Init();
    n.Add(20);
    n.Add(12);
    n.Add(24);
    n.Add(72);
    n.Print();
    n.Sort();
    n.Print();
    return 0 ;
}