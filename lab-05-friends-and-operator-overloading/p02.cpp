/*
    Lab 5
    Understanding the Concept of Friend Function/Class and Operator Overloading
    2.  Write a class to store x, y, and z coordinates of a point in three-dimensional space.
        Overload addition and subtraction operators for addition and subtraction of two coordinate objects.
        Implement the operator functions as non-member functions (friend operator functions).
*/

#include <iostream>

class Coordinate
{
private:
    float _x, _y, _z;

public:
    Coordinate(float x, float y, float z) : _x{x}, _y{y}, _z{z} {}

    void display()
    {
        std::cout << "(" << _x << ", " << _y << ", " << _z << ")";
    }

    // Note: friend functions are not members of the class
    friend Coordinate operator+(const Coordinate &c1, const Coordinate &c2)
    {
        // Private members can be accessed because this is a friend function
        return Coordinate(c1._x + c2._x, c1._y + c2._y, c1._z + c2._z);
    }
};

int main()
{
    Coordinate c1(1, 5, 3), c2(3, 7, 0);

    // c1.operator+(c2) raises an error because Coordinate::operator+() is not a member function
    Coordinate c3 = c1 + c2;

    c3.display();

    return 0;
}
