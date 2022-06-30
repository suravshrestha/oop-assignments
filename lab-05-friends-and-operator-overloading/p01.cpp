/*
    Lab 5
    Understanding the Concept of Friend Function/Class and Operator Overloading
    1.  Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.
        A.  Make a particular member function of one class as a friend function of
            another class for addition.
        B.  Make the other three functions to work as a bridge between the classes for
            multiplication, division, and subtraction.
        C.  Also write a small program to demonstrate that all the member functions of one class are
            the friend functions of another class if the former class is made friend to the latter.
        Make least possible classes to demonstrate all the above in a single program without conflict.
*/

#include <iostream>

// Forward declaration of class Coordinate_
class Coordinate_;

class Number
{
private:
    float _val;

public:
    Number(float val) : _val{val} {}

    // Make class Coordinate a friend of class Number
    friend class Coordinate;
};

class Coordinate
{
private:
    float _x, _y;

public:
    Coordinate(float x, float y) : _x{x}, _y{y} {}

    // Forward declaration above needed for this declaration line
    Coordinate operator+(const Coordinate_ &c);

    // Note: friend functions are not members of the class
    friend Coordinate operator-(const Coordinate &c1, const Coordinate_ &c2);

    Coordinate operator*(Number n);
    Coordinate operator/(Number n);

    void display()
    {
        std::cout << "(" << _x << ", " << _y << ")" << '\n';
    }
};

class Coordinate_
{
private:
    float _x, _y;

public:
    Coordinate_(float x, float y) : _x{x}, _y{y} {}

    // Make member function Coordinate::operator+ a friend of class Coordinate_
    friend Coordinate Coordinate::operator+(const Coordinate_ &c);

    // Note: friend functions are not members of the class
    friend Coordinate operator-(const Coordinate &c1, const Coordinate_ &c2);
};

Coordinate Coordinate::operator+(const Coordinate_ &c)
{
    // Private members of Coordinate_ object can be accessed because
    // this is a friend function of class Coordinate_
    return Coordinate(_x + c._x, _y + c._y);
}

Coordinate operator-(const Coordinate &c1, const Coordinate_ &c2)
{
    return Coordinate(c1._x - c2._x, c1._y - c2._y);
}

Coordinate Coordinate::operator*(Number n)
{
    // All the private members of class Number can be accessed because
    // class Coordinate is a friend of class Number
    return Coordinate(_x * n._val, _y * n._val);
}

Coordinate Coordinate::operator/(Number n)
{
    return Coordinate(_x / n._val, _y / n._val);
}

int main()
{
    Coordinate c1(1, 2);
    Coordinate_ c2(3, 4);

    Coordinate c3 = c1 + c2; // c1.operator+(c2)
    c3.display();

    // c3 = c2 - c1 raises error because operator-(Coordinate_, Coordinate) is not defined
    // c1.operator-(c2) raises error because Coordinate::operator-() is not a member function
    c3 = c1 - c2;
    c3.display();

    c3 = c3 * Number(3);
    c3.display();

    c3 = c3 / Number(5);
    c3.display();

    return 0;
}
