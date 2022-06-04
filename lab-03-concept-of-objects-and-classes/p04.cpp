/*
    Lab 3
    Concept of Objects and Classes
    4.  Write a program with classes to represent a circle, rectangle, and triangle.
        Each class should have data members to represent the actual objects and member
        functions to read and display objects, find perimeter and area of the objects,
        and other useful functions. Use the classes to create objects in your program.
*/

#include <iostream>
#include <cmath>

class Circle
{
private:
    float _radius;
    const float PI = 3.14159;

public:
    // Initializing member using constructor initialization list
    Circle(float r) : _radius{r} {}

    float getArea()
    {
        return PI * _radius * _radius;
    }

    float getPerimeter()
    {
        return 2 * PI * _radius;
    }

    float getRadius()
    {
        return _radius;
    }
};

class Rectangle
{
private:
    float _length, _breadth;

public:
    Rectangle(float l, float b) : _length{l}, _breadth(b) {}

    float getArea()
    {
        return _length * _breadth;
    }

    float getPerimeter()
    {
        return 2 * (_length + _breadth);
    }

    float getLength()
    {
        return _length;
    }

    float getBreadth()
    {
        return _breadth;
    }
};

class Triangle
{
private:
    float _a, _b, _c;

public:
    Triangle(float a, float b, float c) : _a{a}, _b{b}, _c{c} {}

    float getArea()
    {
        float s = getPerimeter() / 2.0f;
        return sqrt(fabs(s * (s - _a) * (s - _b) * (s - _c)));
    }

    float getPerimeter()
    {
        return _a + _b + _c;
    }

    float getSideA()
    {
        return _a;
    }

    float getSideB()
    {
        return _b;
    }

    float getSideC()
    {
        return _c;
    }
};

int main()
{
    Circle c{3};
    Rectangle r{5, 7};
    Triangle t{5, 6, 7};

    std::cout << "Circle with radius " << c.getRadius() << ":\n";
    std::cout << "Area: " << c.getArea() << '\n';
    std::cout << "Perimeter: " << c.getPerimeter() << '\n';

    std::cout << "\nRectangle with length " << r.getLength() << " and breadth " << r.getBreadth() << ":\n";
    std::cout << "Area: " << r.getArea() << '\n';
    std::cout << "Perimeter: " << r.getPerimeter() << '\n';

    std::cout << "\nTriangle with sides " << t.getSideA() << ", " << t.getSideB() << ", " << t.getSideC() << ":\n";
    std::cout << "Area: " << t.getArea() << '\n';
    std::cout << "Perimeter: " << t.getPerimeter() << '\n';

    return 0;
}
