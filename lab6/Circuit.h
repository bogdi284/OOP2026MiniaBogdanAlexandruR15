#pragma once

#include "Weather.h"

#include "Car.h"

class Circuit {
    private:
        double length;
        Weather weather;
        Car* cars[100];
        int numCars;
        struct Result {
            Car* car;
            double finishTime;
            bool finished;
        };
        Result results[100];
    
    public:
        Circuit();
        ~Circuit();
        void SetLength(double l);
        void SetWeather (Weather w);
        void AddCar (Car* c);
        void Race();
        void ShowFinalRanks();
        void ShowWhoDidNotFinish();
};