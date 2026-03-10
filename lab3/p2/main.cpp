#include <iostream>

#include "Canvas.h"

int main () {
    Canvas c(60 , 50) ;
    c.SetPoint(5 ,5 , '*');
    c.Print();
    c.Clear();

    c.DrawLine(0 , 0 ,59 ,37 , '+');
    c.DrawLine(0 , 29 , 59 , 37 , '-');
    c.Print();
    c.Clear();

    c.DrawRect(5, 3 , 20 , 12 , '*');
    c.Print();
    c.Clear();

    c.FillRect(5 , 3 , 20 , 12 , '+');
    c.Print();
    c.Clear();

    c.DrawCircle(20 , 15 , 7 ,'%');
    c.Print();
    c.Clear();

    c.FillCircle(30 , 15 , 8 ,'$');
    c.Print();
    c.Clear();
    return 0;
}