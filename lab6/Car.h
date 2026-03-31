#pragma once

#include "Weather.h"

class Car {
    public:
        virtual double GetFuelCapacity() const = 0;
        virtual double GetFuelConsumption() const = 0;
        virtual double GetAverageSpeed(Weather condition) const = 0;
        virtual const char* GetName() const = 0;
        virtual ~Car() = default;
};