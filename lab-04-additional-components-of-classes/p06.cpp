/*
    Lab 4
    Additional Components of a Class
    6.  Create a class with a data member to hold a "serial number" for each object created from the
        class. That is, the first object created will be numbered 1, the second 2, and so on by using the
        basic concept of static data members. Use static member function if it is useful in the program.
        Otherwise, make a separate program that demonstrates the use of static member function.
*/

#include <iostream>

class Item
{
private:
    // Static data member; initialized only once and is common to all instances of the class
    static int _serial_number; // Declaration
    int _item_number;

    int _foo = 5; // Non-static data member

public:
    Item()
    {
        increaseSerialNumber();
        _item_number = _serial_number;
    }

    static int increaseSerialNumber()
    {
        // ++_foo; // Only static members can be accessed in static member function
        ++_serial_number;
    }

    int getItemNumber()
    {
        // return _foo; // Only static members can be accessed in static member function
        return _item_number;
    }
};

// non-const static data members should be declared and defined separately
int Item::_serial_number = 0;

int main()
{
    Item i1, i2, i3;

    std::cout << "Item 1 no.: " << i1.getItemNumber() << '\n';
    std::cout << "Item 2 no.: " << i2.getItemNumber() << '\n';
    std::cout << "Item 3 no.: " << i3.getItemNumber();

    return 0;
}
