#include "global.h"

int compareName (student s1 , student s2) {
    if (s1.getName() == s2.getName()) {
        return 0;
    }
    else {
        return (s1.getName() > s2.getName()) ? 1 : -1;
    }
}
int compareMath (student s1 , student s2) {
    if (s1.getMathGrade() == s2.getMathGrade()) {
        return 0;
    }
    else {
        return (s1.getMathGrade()>s2.getMathGrade()) ? 1 : -1 ;
    }
}
int compareEnglish (student s1 , student s2) {
    if (s1.getEnglishGrade() == s2.getEnglishGrade()) {
        return 0;
    }
    else {
        return (s1.getEnglishGrade()>s2.getEnglishGrade()) ? 1 : -1;
    }
}
int compareHistory (student s1 , student s2) {
    if (s1.getHistoryGrade() == s2.getHistoryGrade()) {
        return 0;
    }
    else {
        return (s1.getHistoryGrade()>s2.getHistoryGrade()) ? 1 : -1;
    }
}
int compareAverage (student s1 , student s2) {
    if (s1.average() == s2.average ()) {
        return 0;
    }
    else {
        return (s1.average()>s2.average()) ? 1 : -1;
    }
}