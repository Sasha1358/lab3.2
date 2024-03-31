// Car.h
#pragma once
#include <string>
#include <iostream>

class Car {
private:
    std::string* brand;
    std::string color;
    double engineVolume;
    double power;

public:
    Car();
    Car(const std::string& brand, const std::string& color, double engineVolume, double power);
    Car(const Car& other);
    ~Car();

    std::string getBrand() const;
    std::string getColor() const;
    double getEngineVolume() const;
    double getPower() const;

    void setBrand(const std::string& brand);
    void setColor(const std::string& color);
    void setEngineVolume(double engineVolume);
    void setPower(double power);

    void reassignBrand(const std::string& newBrand);

    operator std::string() const;
    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend std::istream& operator>>(std::istream& in, Car& car);
};

