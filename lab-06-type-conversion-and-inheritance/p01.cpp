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

    // Overload the float operator to convert the distance to meters
    operator float()
    {
        return _meter + _centimeter / 100.0f;
    }

    int getMeter() const { return _meter; }
    int getCentimeter() const { return _centimeter; }
};

int main()
{
    Distance d(1, 53);

    std::cout << d.getMeter() << "m " << d.getCentimeter() << "cm = " << float(d) << "m" << '\n';

    return 0;
}
