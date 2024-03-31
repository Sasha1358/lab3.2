// Car.cpp
#include "Car.h"
#include <iostream>

Car::Car() : brand(new std::string()), color(""), engineVolume(0.0), power(0.0) {}
Car::Car(const std::string& brand, const std::string& color, double engineVolume, double power)
    : brand(new std::string(brand)), color(color), engineVolume(engineVolume), power(power) {}
Car::Car(const Car& other)
    : brand(new std::string(*other.brand)), color(other.color), engineVolume(other.engineVolume), power(other.power) {}
Car::~Car() {
    delete brand;
}

std::string Car::getBrand() const {
    return *brand;
}
std::string Car::getColor() const {
    return color;
}
double Car::getEngineVolume() const {
    return engineVolume;
}
double Car::getPower() const {
    return power;
}

void Car::setBrand(const std::string& brand) {
    if (!brand.empty())
        *this->brand = brand;
    else
        std::cerr << "Error: Brand cannot be empty!" << std::endl;
}
void Car::setColor(const std::string& color) {
    this->color = color;
}
void Car::setEngineVolume(double engineVolume) {
    if (engineVolume >= 0)
        this->engineVolume = engineVolume;
    else
        std::cerr << "Error: Engine volume cannot be negative!" << std::endl;
}
void Car::setPower(double power) {
    if (power >= 0)
        this->power = power;
    else
        std::cerr << "Error: Power cannot be negative!" << std::endl;
}

void Car::reassignBrand(const std::string& newBrand) {
    setBrand(newBrand);
}

Car::operator std::string() const {
    return "Brand: " + *brand + ", Color: " + color + ", Engine Volume: " + std::to_string(engineVolume) + ", Power: " + std::to_string(power);
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Brand: " << *car.brand << ", Color: " << car.color << ", Engine Volume: " << car.engineVolume << ", Power: " << car.power;
    return out;
}
std::istream& operator>>(std::istream& in, Car& car) {
    std::cout << "Enter brand: ";
    if (!(in >> *car.brand) || car.brand->empty()) {
        std::cerr << "Error: Invalid brand input!" << std::endl;
        return in;
    }
    std::cout << "Enter color: ";
    in >> car.color;
    std::cout << "Enter engine volume: ";
    if (!(in >> car.engineVolume) || car.engineVolume < 0) {
        std::cerr << "Error: Invalid engine volume input!" << std::endl;
        return in;
    }
    std::cout << "Enter power: ";
    if (!(in >> car.power) || car.power < 0) {
        std::cerr << "Error: Invalid power input!" << std::endl;
        return in;
    }
    return in;
}