#include "RangeRover.h"

double RangeRover::GetFuelCapacity() const {
    return 85.0;
}
double RangeRover::GetFuelConsumption() const {
    return 12.0;
}
double RangeRover::GetAverageSpeed(Weather condition) const {
    if (condition == Weather::Sunny) {
        return 140.0;
    }
    else if (condition == Weather::Rain) {
        return 120.0;
    }
    else {
        return 90.0;
    }
}
const char* RangeRover::GetName() const {
    return "RangeRover";
}