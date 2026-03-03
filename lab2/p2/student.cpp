#include "student.h"

student::student(char* name , float math , float english , float history) {
    this->name = name ;
    this->mathGrade = math ;
    this->englishGrade = english ;
    this->historyGrade = history ;
}
void student::setName (char* name) {
    this->name = name ;
}
char* student::getName () {
    return name;
}
void student::setMathGrade (float grade) {
    this->mathGrade = grade ;
}
float student::getMathGrade () {
    return mathGrade;
}
void student::setEnglishGrade (float grade) {
    this->englishGrade = grade ;
}
float student::getEnglishGrade () {
    return englishGrade ;
}
void student::setHistoryGrade (float grade) {
    this->historyGrade = grade ;
}
float student::getHistoryGrade () {
    return historyGrade ;
}
float student::average () {
    float avg ;
    avg = (mathGrade + englishGrade + historyGrade ) / 3.0;
    return avg;
}