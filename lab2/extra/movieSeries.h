#pragma once

#include "movie.h"

class MovieSeries {
    private:
        int moviesCount ;
        Movie* movieList[16];
    public:
        void init ();
        bool add(Movie* movie) ;
        void sort();
        void print();
};