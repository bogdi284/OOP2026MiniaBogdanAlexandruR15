#include "movieGlobal.h"

int movie_compare_name (Movie m1 , Movie m2) {
    if (m1.get_name() == m2.get_name()) {
        return 0;
    }
    else {
        return (m1.get_name() > m2.get_name()) ? 1 : -1;
    }
}
int movie_compare_year (Movie m1 , Movie m2) {
    if (m1.get_year() == m2.get_year()) {
        return 0;
    }
    else {
        return (m1.get_year() > m2.get_year()) ? 1 : -1;
    }
}
int movie_compare_score (Movie m1 , Movie m2) {
    if (m1.get_score() == m2.get_score()) {
        return 0;
    }
    else {
        return (m1.get_score() > m2.get_score()) ? 1 : -1;
    }
}
int movie_compare_length (Movie m1 , Movie m2) {
    if (m1.get_score() == m2.get_score()) {
        return 0;
    }
    else {
        return (m1.get_score() > m2.get_score()) ? 1 : -1;
    }
}
int movie_compare_passed_years (Movie m1 , Movie m2) {
    if (m1.get_yearsPassed() == m2.get_yearsPassed()) {
        return 0;
    }
    else {
        return (m1.get_yearsPassed() > m2.get_yearsPassed()) ? 1 : -1;
    }
}