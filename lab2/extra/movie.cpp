#include "movie.h"
Movie::Movie () {}
Movie::Movie(char* name , int year , double imdbScore , int length) {
    this->name = name;
    this->year = year ;
    this->imdbScore = imdbScore;
    this->length = length;
}
void Movie::set_name(char* name) {
    this->name = name;
}
char* Movie::get_name() {
    return name ;
}
void Movie::set_year (int year) {
    this->year = year ;
}
int Movie::get_year () {
    return year;
}
void Movie::set_score (double imdbScore) {
    this->imdbScore = imdbScore;
}
double Movie::get_score () {
    return imdbScore;
}
void Movie::set_length (int length) {
    this->length = length;
}
int Movie::get_length () {
    return length;
}
int Movie::get_yearsPassed () {
    int yearsPassed ;
    yearsPassed = 2026 - year ;
    return yearsPassed;
}
