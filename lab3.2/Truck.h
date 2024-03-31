// Truck.h
#pragma once
#include "Car.h"

class Truck : public Car {
private:
    double cargoCapacity;

public:
    Truck();
    Truck(const std::string& brand, const std::string& color, double engineVolume, double power, double cargoCapacity);
    Truck(const Truck& other);
    ~Truck();

    double getCargoCapacity() const;
    void setCargoCapacity(double cargoCapacity);

    void reassignCargoCapacity(double newCapacity);

    operator std::string() const;

    friend std::ostream& operator<<(std::ostream& out, const Truck& truck);
    friend std::istream& operator>>(std::istream& in, Truck& truck);
};
