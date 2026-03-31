#include "BMW.h"

double BMW::GetFuelCapacity() const {
    return 60.0;
}
double BMW::GetFuelConsumption() const {
    return 10.8;
}
double BMW::GetAverageSpeed(Weather condition) const {
    if (condition == Weather::Sunny) {
        return 160.0;
    }
    else if (condition == Weather::Rain) {
        return 110.0;
    }
    else {
        return 80.0;
    }
}
const char* BMW::GetName() const {
    return "BMW";
}