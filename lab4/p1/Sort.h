#pragma once
#include <initializer_list>

class Sort
{
private:
    int *list;
    int count;
    void QuickSortHelper (int low , int high , bool ascendent);
    int Partition(int low , int high , bool ascendent);
public:
    Sort(int count ,int minVal , int maxVal);
    Sort(std::initializer_list<int> list);
    Sort(int *list , int count) ;
    Sort(int count , ...);
    Sort(const char* str);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
    ~Sort();
};
