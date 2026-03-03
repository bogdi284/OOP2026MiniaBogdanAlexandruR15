#include <iostream>
#include "movieSeries.h"

void MovieSeries::init () {
    this->moviesCount = 0;
}
bool MovieSeries::add(Movie* movie) {
    if (moviesCount < 16 && movie!=nullptr) {
        movieList[moviesCount] = movie ;
        moviesCount++;
        return true;
    }
    std::cout << "the movies list is full!" << '\n';
    return false;
}
void MovieSeries::sort() {
    for (int i = 0 ; i < moviesCount - 1 ; i++) {
        for (int j = i+1 ; j < moviesCount ; j++) {
            if (movieList[i]->get_yearsPassed() > movieList[j]->get_yearsPassed()) {
                Movie* aux ;
                aux = movieList[i] ;
                movieList[i] = movieList[j];
                movieList[j] = aux;
            }
        }
    }
}
void MovieSeries::print() {
    for (int i = 0 ; i < moviesCount ; i++) {
        std::cout<<movieList[i]->get_name()<<'\n';
        std::cout<<movieList[i]->get_year()<<'\n';
        std::cout<<movieList[i]->get_score()<<'\n';
        std::cout<<movieList[i]->get_length()<<'\n';
        std::cout<<movieList[i]->get_yearsPassed()<<'\n';
    }
    std::cout<<'\n';
}