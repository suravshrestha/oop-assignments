/*
    Lab 7
    Understanding the Concept of Virtual Function, Virtual Base Class, and RTTI
    4.  Create a polymorphic class Vehicle and create other derived classes Bus, Car, and
        Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in
        this program.
*/

#include <iostream>
#include <typeinfo> // typeid

class Vehicle
{
public:
    // For dynamic downcasting, base class must have at least one virtual function
    virtual void print()
    {
        std::cout << "Vehicle\n";
    }
};

class Bus : public Vehicle
{
public:
    void print() override
    {
        std::cout << "Bus\n";
    }
};

class Car : public Vehicle
{
public:
    void print() override
    {
        std::cout << "Car\n";
    }
};

class Bike : public Vehicle
{
public:
    void print() override
    {
        std::cout << "Bike\n";
    }
};

int main()
{
    Bus bus;

    // Upcasting - Casting derived class to base class
    Vehicle *vp = &bus;

    // Downcasting - Dynamic casting base class to derived class
    Bus *busp = dynamic_cast<Bus *>(vp);

    if (busp == nullptr)
    {
        std::cout << "busp is nullptr\n";
        return -1;
    }

    busp->print();

    // Display information containing the name of the type
    std::cout << typeid(bus).name() << '\n';
    std::cout << typeid(vp).name() << '\n';
    std::cout << typeid(*busp).name(); // Information about the object pointed by busp

    return 0;
}
