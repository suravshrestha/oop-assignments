/*
    Lab 7
    Understanding the Concept of Virtual Function, Virtual Base Class, and RTTI
    1.  Write a program to create a class shape with functions to find the area of the
        shapes and display the names of the shapes and other essential components of the class.
        Create derived classes circle, rectangle, and trapezoid each having overriding functions
        area() and display(). Write a suitable program to illustrate virtual functions and virtual
        destructors.
*/

#include <iostream>

class Shape
{
public:
    virtual ~Shape()
    {
        std::cout << "Calling ~Shape()\n\n";
    }

    virtual float area()
    {
        return 0;
    }

    virtual void display()
    {
        std::cout << "Shape\n";
    }
};

class Circle : public Shape
{
private:
    const int PI = 3.14159;
    float _radius;

public:
    Circle(float r) : _radius{r} {}

    // Override keyword is used just to show the reader that,
    // "this is a virtual method, that is overriding a virtual method of the base class."
    ~Circle() override
    {
        std::cout << "Calling ~Circle()\n";
    }

    // Overriding functions of the base class Shape
    float area() override
    {
        return PI * _radius * _radius;
    }

    void display() override
    {
        std::cout << "Circle\n";
    }
};

class Rectangle : public Shape
{
private:
    float _length, _breadth;

public:
    Rectangle(float l, float b) : _length{l}, _breadth{b} {}

    ~Rectangle()
    {
        std::cout << "Calling ~Rectangle()\n";
    }

    float area() override
    {
        return _length * _breadth;
    }

    void display() override
    {
        std::cout << "Rectangle\n";
    }
};

class Trapezoid : public Shape
{
private:
    float _a, _b; // Parallel sides
    float _h;     // Height

public:
    Trapezoid(float a, float b, float h) : _a{a}, _b{b}, _h{h} {}

    float area() override
    {
        return 0.5f * (_a + _b) * _h;
    }

    void display() override
    {
        std::cout << "Trapezoid\n";
    }
};

int main()
{
    Shape *shapes[3];
    Circle c(5);
    Rectangle r(3, 7);
    Trapezoid t(7, 3, 5);

    shapes[0] = &c;
    shapes[1] = &r;
    shapes[2] = &t;

    // If the functions in class Shape are not made virtual, the method will be called of the
    // Shape object, and not of the object pointed by the Shape pointer.
    std::cout << shapes[0]->area() << '\n';
    shapes[1]->display();
    std::cout << shapes[2]->area() << '\n';

    // Destructor is made virtual so destructor of the object pointed (derived class) is called first
    delete shapes[0];
    delete shapes[1];

    // Call the default constructor ~Trapezoid() (which in turn calls the ~Shape())
    delete shapes[2];

    return 0;
}
