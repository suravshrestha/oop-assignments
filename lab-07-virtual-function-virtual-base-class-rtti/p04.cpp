/*
    Lab 7
    Understanding the Concept of Virtual Function, Virtual Base Class, and RTTI
    4.  Create a polymorphic class Vehicle and create other derived classes Bus, Car, and
        Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in
        this program.
*/

#include <iostream>
#include <typeinfo> // typeid

using namespace std;

class Vehicle
{
public:
    // For dynamic downcasting, base class must have at least one virtual function
    virtual void print()
    {
        cout << "Vehicle" << '\n';
    }
};

class Bus : public Vehicle
{
public:
    void print() override
    {
        cout << "Bus" << '\n';
    }
};

class Car : public Vehicle
{
public:
    void print() override
    {
        cout << "Car" << '\n';
    }
};

class Bike : public Vehicle
{
public:
    void print() override
    {
        cout << "Bike" << '\n';
    }
};

int main()
{
    Bus bus;

    // Upcasting - Casting derived class to base class
    Vehicle *vp = &bus;

    // Downcasting - Dynamic casting base class to derived class
    Bus *bp = dynamic_cast<Bus *>(vp);

    if (bp == nullptr)
    {
        cout << "cp is nullptr\n";
        return -1;
    }

    vp->print();
    bp->print();

    // Store information about type of the object
    const type_info &type_bus = typeid(bus);
    const type_info &type_vp = typeid(vp);
    const type_info &type_bp = typeid(bp);

    // Display name of the type
    cout << type_bus.name() << '\n';
    cout << type_vp.name() << '\n';
    cout << type_bp.name();

    return 0;
}
