#include "Fiat.h"

double Fiat::GetFuelCapacity() const {
    return 25.0;
}
double Fiat::GetFuelConsumption() const {
    return 5.0;
}
double Fiat::GetAverageSpeed(Weather condition) const {
    if (condition == Weather::Sunny) {
        return 100.0;
    }
    else if (condition == Weather::Rain) {
        return 70.0;
    }
    else {
        return 50.0;
    }
}
const char* Fiat::GetName() const {
    return "Fiat";
}