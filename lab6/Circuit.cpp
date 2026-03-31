#include "Circuit.h"

#include <iostream>

Circuit::Circuit() {
    this->length = 0;
    this->weather = Weather::Sunny;
    this->numCars = 0;
}
Circuit::~Circuit() {
    for (int i = 0 ; i < numCars ; i++) {
        delete cars[i];
    }
}
void Circuit::SetLength(double l){
    length = l;
}
void Circuit::SetWeather(Weather w){
    weather = w;
}
void Circuit::AddCar(Car* c){
    if(numCars < 100) {
        cars[numCars++] = c;
    }
}
void Circuit::Race(){
    for (int i = 0 ; i< numCars ; i++) {
        results[i].car = cars[i];
        double requiredFuel = (length / 100.0)*cars[i]->GetFuelConsumption();
        if(requiredFuel <= cars[i]->GetFuelCapacity()) {
            results[i].finished = true;
            results[i].finishTime = length / cars[i]->GetAverageSpeed(weather);
        }
        else {
            results[i].finished = false;
            results[i].finishTime = -1.0;
        }
    }
    for (int i=0 ; i<numCars-1 ; i++) {
        for (int j = i+1 ; j<numCars; j++) {
            if(results[i].finished && results[j].finished) {
                if(results[i].finishTime > results[j].finishTime) {
                    Result temp = results[i];
                    results[i]=results[j];
                    results[j]= temp;
                }
            }
            else if (!results[i].finished && results[j].finished) {
                Result temp = results[i];
                results[i]=results[j];
                results[j]=temp;
            }
        }
    }
}
void Circuit::ShowFinalRanks() {
    std::cout<<"Final Ranks \n";
    for (int i=0 ; i< numCars ; i++) {
        if(results[i].finished) {
            std::cout<<i+1<<"."<<results[i].car->GetName()<<"-Time:"<<results[i].finishTime<<"hours\n";
        }
    }
}
void Circuit::ShowWhoDidNotFinish() {
    std::cout<<"\n did not finish \n";
    for(int i=0 ; i<numCars ;i++) {
        if(!results[i].finished) {
            std::cout<<results[i].car->GetName()<<"\n";
        }
    }
}