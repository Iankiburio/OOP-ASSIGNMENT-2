//design of abstract base
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;
public:
    Vehicle(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr) {}
    virtual double calculateRentalCost() = 0;
    virtual void displayInfo() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }
    virtual ~Vehicle() {}
};

//three derived classes

class Car : public Vehicle {
    int numDoors;
public:
    Car(string mk, string mdl, int yr, int doors) : Vehicle(mk, mdl, yr), numDoors(doors) {}
    double calculateRentalCost() override {
        return 50.0; //I used a fixed cost
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class SUV : public Vehicle {
    bool fourWheelDrive;
public:
    SUV(string mk, string mdl, int yr, bool fwd) : Vehicle(mk, mdl, yr), fourWheelDrive(fwd) {}
    double calculateRentalCost() override {
        return 75.0; //I used a fixed cost
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Four Wheel Drive: " << (fourWheelDrive ? "Yes" : "No") << endl;
    }
};

class Truck : public Vehicle {
    double cargoCapacity;
public:
    Truck(string mk, string mdl, int yr, double capacity) : Vehicle(mk, mdl, yr), cargoCapacity(capacity) {}
    double calculateRentalCost() override {
        return 100.0; //I used a fixed cost
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
    }
};

//main function 
int main() {
    Car car1("Toyota", "Premio", 2020, 4);
    SUV suv1("Ford", "Ranger", 2021, true);
    Truck truck1("Honda", "CRV", 2019, 20.0);

    Vehicle* vehicles[] = { &car1, &suv1, &truck1 };

    for (Vehicle* v : vehicles) {
        v->displayInfo();
        cout << "Rental Cost: $" << v->calculateRentalCost() << endl;
        cout << "-----------------------------" << endl;
    }
    return 0;
}
