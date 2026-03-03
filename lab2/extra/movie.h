#pragma once

class Movie {
    private:
        char *name;
        int year;
        double imdbScore;
        int length;
    public:
        Movie();
        Movie(char* name, int year , double imdbScore , int length);
        void set_name(char* name);
        char* get_name();
        void set_year (int year);
        int get_year ();
        void set_score (double imdbScore) ;
        double get_score ();
        void set_length (int length);
        int get_length ();
        int get_yearsPassed ();
};