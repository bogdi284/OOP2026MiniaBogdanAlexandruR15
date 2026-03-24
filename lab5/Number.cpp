#include "Number.h"
#include <iostream>
#include <cstring>

long long Number::getBase10() const {
    long long val10 = 0;
    long long p = 1;
    int len = strlen(value);

    for(int i = len - 1 ; i >= 0 ; i--) {
        int digit = 0;
        if (value[i] >= '0' && value[i] <= '9') {
            digit = value[i] - '0';
        }
        else if(value[i] >='A' && value[i] <= 'F') {
            digit = value[i] - 'A' + 10;
        }
        val10 += digit*p;
        p *= base;
    }
    return val10;
}
void Number::setFromBase10(long long val10 , int newBase) {
    if (value !=nullptr) {
        delete[] value;
    }
    this->base = newBase;
    if(val10 == 0) {
        value = new char[2];
        value[0] = '0';
        value[1] = '\0';
        return;
    }
    char buff[100];
    int index = 0;
    long long temp = val10;

    while (temp > 0) {
        int rem =  temp % newBase;
        if (rem < 10) {
            buff[index] = rem + '0';
            index++;
        }
        else {
            buff[index] = rem - 10 + 'A';
            index++;
        }
        temp /= newBase ;
    }
    value = new char[index + 1];
    for (int i = 0 ; i < index ; i++) {
        value[i] = buff[index - 1 - i];
    }
    value[index] = '\0';
}
Number::Number(const char* val , int base) {
    this->base = base;
    this->value = new char[strlen(val)+1];
    strcpy(this->value , val);
}
Number::Number(int value) {
    base = 10;
    this->value = nullptr;
    setFromBase10(value , 10);
}
Number::~Number() {
    if (value!=nullptr) {
        delete[] value;
        value = nullptr;
    }
}
Number::Number(const Number& other) {
    base = other.base;
    value = new char[strlen(other.value) + 1];
    strcpy(value , other.value);
}
Number::Number(Number&& other) {
    base = other.base;
    value = other.value;

    other.base = 0;
    other.value = nullptr;
}
Number& Number::operator=(const Number& other) {
    if(this != &other) {
        delete[] value;
        base = other.base;
        value = new char[strlen(other.value)+1];
        strcpy(value , other.value);
    }
    return *this;
}
Number& Number::operator=(Number&& other) {
    if (this != &other ) {
        delete[] value;
        base = other.base;
        value = other.value;

        other.value = nullptr;
        other.base = 0;
    }
    return *this;
}
Number& Number::operator=(int value) {
    setFromBase10(value , this->base);
    return *this;
}
Number& Number::operator=(const char* s) {
    long long val10 = 0;
    for (int i=0 ; s[i] != '\0' ; ++i) {
        val10 = val10 * 10 + (s[i] - '0');
    }
    setFromBase10(val10 , this->base);
    return *this;
}
void Number::SwitchBase(int newBase) {
    if (newBase == base) return;
    long long val10 = getBase10();
    setFromBase10(val10 , newBase);
}
void Number::Print() {
    std::cout<<value<<'\n';
}
int Number::GetDigitsCount() {
    return strlen(value);
}
int Number::GetBase() {
    return base;
}
char Number::operator[](int index){
    if(index>=0 && index<(int)strlen(value)) {
        return value[index];
    }
    return '\0';
}
Number& Number::operator--() {
    if(strlen(value)>1){
        int len = strlen (value);
        for(int i=0 ; i<len ; i++) {
            value[i] = value[i+1];
        }
    }
    else {
        value[0] = '0';
    }
    return *this;
}
Number Number::operator--(int) {
    Number temp(*this);
    if (strlen(value) > 1){
        value[strlen(value) - 1] = '\0';
    }
    else {
        value[0] = '0';
    }
    return temp;
}
Number& Number::operator+=(const Number& other) {
    long long sum = this->getBase10() + other.getBase10();
    int maxBase = (this->base > other.base) ? this->base : other.base;
    setFromBase10(sum , maxBase);
    return *this;
}
Number operator+(const Number& n1 , const Number& n2) {
    long long sum = n1.getBase10() + n2.getBase10();
    int maxBase = (n1.base > n2.base) ? n1.base : n2.base ;
    Number result("0" , maxBase);
    result.setFromBase10(sum , maxBase);
    return result;
}
Number operator-(const Number& n1 , const Number& n2) {
    long long diff = n1.getBase10() - n2.getBase10();
    if(diff<0) {
        diff=0;
    }
    int maxBase = (n1.base > n2.base) ? n1.base : n2.base ;
    Number result("0" , maxBase);
    result.setFromBase10(diff , maxBase);
    return result;
}
bool operator>(const Number& n1 , const Number& n2) {
    return n1.getBase10()>n2.getBase10();
}
bool operator<(const Number& n1 , const Number& n2) {
    return n1.getBase10()<n2.getBase10();
}
bool operator>=(const Number& n1 , const Number& n2) {
    return n1.getBase10()>=n2.getBase10();
}
bool operator<=(const Number& n1 , const Number& n2) {
    return n1.getBase10()<=n2.getBase10();
}
bool operator==(const Number& n1 , const Number& n2) {
    return n1.getBase10()==n2.getBase10();
}
bool operator!=(const Number& n1 , const Number& n2) {
    return n1.getBase10()!=n2.getBase10();
}