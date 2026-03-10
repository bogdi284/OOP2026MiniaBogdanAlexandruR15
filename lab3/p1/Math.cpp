#include <string.h>
#include <cstdlib>
#include <cstdarg>
#include "Math.h"

int Math::Add (int a , int b) {
    return a+b;
}
int Math::Add (int a , int b , int c) {
    return a+b+c;
}
int Math::Add (double a , double b) {
    return(int)(a+b);
}
int Math::Add(double a , double b , double c) {
    return(int)(a+b+c);
}
int Math::Mul (int a , int b) {
    return a*b;
}
int Math::Mul (int a , int b , int c) {
    return a*b*c;
}
int Math::Mul (double a , double b) {
    return(int)(a*b);
}
int Math::Mul (double a , double b , double c) {
    return(int)(a*b*c);
}
int Math::Add (int count ,...) {
    int s = 0 ;
    va_list args;
    va_start(args , count);
    for (int i = 0 ; i < count ; i++) {
        s = s + va_arg(args,int);
    }
    va_end(args);
    return s;
}

char* Math::Add(const char* a , const char* b) {
    if (a == nullptr || b == nullptr) {
        return nullptr;
    }
    int la = strlen (a);
    int lb = strlen (b);
    char* res = (char*)malloc(la+lb+1);
    if (res == nullptr) {
        return nullptr;
    }
    strcpy (res , a);
    strcat (res , b);
    return res;
}
