#include "Volvo.h"

double Volvo::GetFuelCapacity() const {
    return 70.0;
}
double Volvo::GetFuelConsumption() const {
    return 8.8;
}
double Volvo::GetAverageSpeed(Weather condition) const {
    if (condition == Weather::Sunny) {
        return 120.0;
    }
    else if (condition == Weather::Rain) {
        return 90.0;
    }
    else {
        return 70.0;
    }
}
const char* Volvo::GetName() const {
    return "Volvo";
}