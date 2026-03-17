#include <iostream>

#include "Sort.h"

int main () {
    Sort s1(10 , 1 , 100);
    s1.Print();
    s1.InsertSort(true);
    s1.Print();
    std::cout<<'\n';

    Sort s2({50 , 20 , 40 , 10 , 30});
    s2.Print();
    s2.BubbleSort(false);
    s2.Print();
    std::cout<<'\n';

    int v[] = {9 , 2 , 7 , 4 , 5};
    Sort s3(v , 5);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();
    std::cout<<'\n';

    Sort s4(6 , 100 ,50 , 75 , 90 , 10 , 25);
    s4.Print();
    s4.QuickSort(true);
    s4.Print();
    std::cout<<'\n';

    Sort s5("10,100,40,5,75");
    s5.Print();
    s5.QuickSort(false);
    s5.Print();
    std::cout<<"Numar total elemente s5: "<<s5.GetElementsCount()<<'\n';
    std::cout<<"Elementul de la indexul 3: "<<s5.GetElementFromIndex(3)<<'\n';
    std::cout<<'\n'; 
    return 0;
}