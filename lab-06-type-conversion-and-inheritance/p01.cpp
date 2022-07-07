/*
    Lab 6
    Understanding the Concept of Type Conversion and Inheritance
    1.  Write a program that can convert the Distance (meter, centimeter) to meters measurement in
        float and vice versa. Make a class distance with two data members, meter and centimeter.
        You can add function members as per your requirement.
*/

#include <iostream>

class Distance
{
private:
    int _meter, _centimeter;

public:
    Distance(int m, int cm) : _meter{m}, _centimeter{cm} {}

    // Basic data type to user-defined data type
    // Convert float to Distance object
    Distance(float m)
    {
        _meter = m;
        _centimeter = (m - _meter) * 100;
    }

    // Overload the float operator to convert the distance to meters
    operator float()
    {
        return _meter + _centimeter / 100.0f;
    }

    void display()
    {
        std::cout << _meter << "m " << _centimeter << "cm";
    }
};

int main()
{
    Distance d(1, 53);
    d.display();
    std::cout << " = " << float(d) << "m" << '\n';

    float m = 1.57;
    Distance d2(m); // d2 = Distance(m)
    std::cout << m << 'm' << " = ";
    d2.display();

    return 0;
}
