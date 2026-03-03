#include "movieGlobal.h"

int compareName (Movie m1 , Movie m2) {
    if (m1.getName() == m2.getName()) {
        return 0;
    }
    else {
        return (m1.getName() > m2.getName()) ? 1 : -1;
    }
}
int compareYear (Movie m1 , Movie m2) {
    if (m1.getYear() == m2.getYear()) {
        return 0;
    }
    else {
        return (m1.getYear() > m2.getYear()) ? 1 : -1;
    }
}
int compareImdbScore (Movie m1 , Movie m2) {
    if (m1.getImdbScore() == m2.getImdbScore()) {
        return 0;
    }
    else {
        return (m1.getImdbScore() > m2.getImdbScore()) ? 1 : -1;
    }
}
int compareLength (Movie m1 , Movie m2) {
    if (m1.getLength() == m2.getLength()) {
        return 0;
    }
    else {
        return (m1.getLength() > m2.getLength()) ? 1 : -1;
    }
}
int compareYearsPassed (Movie m1 , Movie m2) {
    if (m1.getYearsPassed() == m2.getYearsPassed()) {
        return 0;
    }
    else {
        return (m1.getYearsPassed() > m2.getYearsPassed()) ? 1 : -1;
    }
}