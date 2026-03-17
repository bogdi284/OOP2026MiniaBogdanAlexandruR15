#include <iostream>
#include <cstdlib>
#include <cstdarg>

#include "Sort.h"

Sort::Sort (int count , int minVal , int maxVal) {
    this->count = count;
    this->list = new int [count];
    for (int i = 0 ; i < count ; i++) {
        this->list[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}
Sort::Sort (std::initializer_list<int> list) {
    this->count = list.size() ;
    this->list = new int[count] ;
    int i = 0 ;
    for (int val:list) {
        this->list[i] = val;
        i++;
    }
}
Sort::Sort(int* list , int count) {
    this->count = count;
    this->list = new int[count];
    for (int i = 0 ; i<count ; i++) {
        this->list[i] = list[i];
    }
}
Sort::Sort(int count ,...) {
    this->count = count;
    this->list = new int[count];
    va_list args;
    va_start(args , count);
    for (int i = 0 ; i < count ; i++) {
        this->list[i] = va_arg(args , int);
    }
    va_end(args);
}
Sort::Sort(const char* str) {
    this->count = 1;
    for(int i = 0 ; str[i] !='\0' ; i++){
        if (str[i]==',') {
            this->count++;
        }
    }
    this->list = new int[this->count];
    int index = 0;
    int currentNumber = 0;
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == ','){
            this->list[index++] = currentNumber;
            currentNumber = 0;
        }
        else if (str[i]>='0' && str[i]<='9') {
            currentNumber = currentNumber * 10 + (str[i] - '0');
        }
    }
    this->list[index] = currentNumber;
}
Sort::~Sort() {
    delete[] this->list;
}
void Sort::InsertSort(bool ascendent) {
    for (int i = 1 ; i < count ; i++) {
        int key = list[i];
        int j = i - 1;
        bool condition = false;
        while (j>=0) {
            condition = ascendent ? (list[j] > key) : (list[j] < key);
            if (!condition) break;
            list[j+1] = list[j];
            j = j - 1;
        }
        list[j+1] = key;
    }
}
void Sort::BubbleSort(bool ascendent) {
    for (int i = 0 ; i < count - 1 ; i++) {
        for (int j = i+1 ; j<count-i-1 ; j++) {
            bool condition = ascendent ? (list[j]>list[j+1]):(list[j]<list[j+1]);
            if (condition) {
                int aux = list[j];
                list[j] = list[j+1];
                list[j+1] = aux;
            }
        }
    }
}
void Sort::QuickSortHelper(int low , int high , bool ascendent) {
    if (low < high) {
        int pivot = Partition(low , high , ascendent);
        QuickSortHelper(low , pivot - 1 , ascendent);
        QuickSortHelper(pivot + 1 , high , ascendent);  
    }
}
int Sort::Partition(int low , int high , bool ascendent) {
    int pivot = list[high];
    int i = low - 1;
    for (int j = low ; j <= high - 1 ; j++) {
        bool condition = ascendent ? (list[j]<pivot):(list[j]>pivot);
        if(condition) {
            i++;
            int aux = list[i];
            list[i] = list[j];
            list[j] = aux;
        }
    }
    int aux = list[i+1];
    list[i+1] = list[high];
    list[high] = aux;
    return (i+1);
}
void Sort::QuickSort(bool ascendent) {
    if (count>1) {
        QuickSortHelper(0 , count - 1 , ascendent);
    }
}
void Sort::Print(){
    for (int i = 0 ; i<count ; i++) {
        std::cout<<list[i]<<" ";
    }
    std::cout<<'\n';
}
int Sort::GetElementsCount() {
    return count;
}
int Sort::GetElementFromIndex(int index) {
    if (index >=0 && index < count) {
        return list[index];
    }
    return -1;
}