#pragma once
#include <string.h>
#include "movie.h"

Movie::Movie(char* name , int year , double imdbScore , int length) {
    if (name != nullptr) {
        strncpy (this->name , name , 255);
        this->name[255] = '\0';
    }
    else {
        this->name[0] = '\0';
    }
    this->year = year ;
    this->imdbScore = imdbScore;
    this->length = length;
}
void Movie::setName(char name[]) {
    if (name != nullptr) {
        strncpy (this->name , name , 255);
        this->name[255] = '\0';
    }
    else {
        this->name[0] = '\0';
    }
}
char* Movie::getName() {
    return name ;
}
void Movie::setYear (int year) {
    this->year = year ;
}
int Movie::getYear () {
    return year;
}
void Movie::setImdbScore (double imdbScore) {
    this->imdbScore = imdbScore;
}
double Movie::getImdbScore () {
    return imdbScore;
}
void Movie::setLength (int length) {
    this->length = length;
}
int Movie::getLength () {
    return length;
}
int Movie::getYearsPassed () {
    int yearsPassed ;
    yearsPassed = 2026 - year ;
    return yearsPassed;
}
