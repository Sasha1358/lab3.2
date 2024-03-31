// Truck.cpp
#include "Truck.h"
#include <iostream>

Truck::Truck() : cargoCapacity(0.0) {}
Truck::Truck(const std::string& brand, const std::string& color, double engineVolume, double power, double cargoCapacity)
    : Car(brand, color, engineVolume, power), cargoCapacity(cargoCapacity) {}
Truck::Truck(const Truck& other) : Car(other), cargoCapacity(other.cargoCapacity) {}
Truck::~Truck() {}

double Truck::getCargoCapacity() const {
    return cargoCapacity;
}
void Truck::setCargoCapacity(double cargoCapacity) {
    if (cargoCapacity >= 0)
        this->cargoCapacity = cargoCapacity;
    else
        std::cerr << "Error: Cargo capacity cannot be negative!" << std::endl;
}

void Truck::reassignCargoCapacity(double newCapacity) {
    setCargoCapacity(newCapacity);
}

Truck::operator std::string() const {
    return static_cast<std::string>(static_cast<const Car&>(*this)) + ", Cargo Capacity: " + std::to_string(cargoCapacity);
}

std::ostream& operator<<(std::ostream& out, const Truck& truck) {
    out << static_cast<const Car&>(truck) << ", Cargo Capacity: " << truck.cargoCapacity;
    return out;
}
std::istream& operator>>(std::istream& in, Truck& truck) {
    in >> static_cast<Car&>(truck);
    std::cout << "Enter cargo capacity: ";
    if (!(in >> truck.cargoCapacity) || truck.cargoCapacity < 0) {
        std::cerr << "Error: Invalid cargo capacity input!" << std::endl;
        return in;
    }
    return in;
}