#include "Seat.h"

double Seat::GetFuelCapacity() const {
    return 45.0;
}
double Seat::GetFuelConsumption() const {
    return 6.0;
}
double Seat::GetAverageSpeed(Weather condition) const {
    if (condition == Weather::Sunny) {
        return 110.0;
    }
    else if (condition == Weather::Rain) {
        return 80.0;
    }
    else {
        return 60.0;
    }
}
const char* Seat::GetName() const {
    return "Seat";
}