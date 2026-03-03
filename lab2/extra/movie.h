#pragma once

class Movie {
    private:
        char name[256];
        int year;
        double imdbScore;
        int length;
    public:
        Movie();
        Movie(char name[] , int year , double imdbScore , int length);
        void setName(char name[]);
        char* getName();
        void setYear (int year);
        int getYear ();
        void setImdbScore (double imdbScore) ;
        double getImdbScore ();
        void setLength (int length);
        int getLength ();
        int getYearsPassed ();
};