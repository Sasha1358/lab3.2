#include <iostream>
#include "Car.h"
#include "Truck.h"

void displayMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Enter details for a car" << std::endl;
    std::cout << "2. Enter details for a truck" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void demonstrateCarAndTruck() {
    Car car;
    std::cout << "Enter details for a car:" << std::endl;
    std::cin >> car;
    std::cout << "Car details: " << car << std::endl;

    Truck truck(car.getBrand(), car.getColor(), car.getEngineVolume(), car.getPower(), 0.0);
    std::cout << "Enter cargo capacity for the truck:" << std::endl;
    double cargoCapacity;
    if (!(std::cin >> cargoCapacity) || cargoCapacity < 0) {
        std::cerr << "Error: Invalid cargo capacity input!" << std::endl;
        return;
    }
    truck.reassignCargoCapacity(cargoCapacity);
    std::cout << "Truck details: " << truck << std::endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cerr << "Error: Invalid input. Exiting program." << std::endl;
            return 1;
        }

        switch (choice) {
        case 1:
            demonstrateCarAndTruck();
            break;
        case 2:
            std::cerr << "Error: You've already entered details for a car. Please choose option 1 again to enter details for a truck." << std::endl;
            break;
        case 0:
            std::cout << "Thank you for using the program! Goodbye." << std::endl;
            break;
        default:
            std::cerr << "Error: Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
