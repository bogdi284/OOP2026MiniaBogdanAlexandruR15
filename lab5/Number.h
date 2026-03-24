#pragma once

class Number {
    private:
        char* value;
        int base;
        long long getBase10() const;
        void setFromBase10(long long val10 , int newBase);
    public:
        Number(const char* value , int base);
        Number(int value);
        ~Number();

        Number(const Number& other); 
        Number(Number&& other); 

        Number& operator=(const Number& other);
        Number& operator=(Number&& other);

        Number& operator=(int value);
        Number& operator=(const char* s);

        void SwitchBase(int newBase);
        void Print();
        int GetDigitsCount();
        int GetBase();

        char operator[](int index);

        Number& operator--();
        Number operator--(int);

        Number& operator+=(const Number& other);
        
        friend Number operator+(const Number& n1 , const Number& n2);
        friend Number operator-(const Number& n1 , const Number& n2);

        friend bool operator>(const Number& n1 , const Number& n2);
        friend bool operator<(const Number& n1 , const Number& n2);
        friend bool operator>=(const Number& n1 , const Number& n2);
        friend bool operator<=(const Number& n1 , const Number& n2);
        friend bool operator==(const Number& n1 , const Number& n2);
        friend bool operator!=(const Number& n1 , const Number& n2);
};