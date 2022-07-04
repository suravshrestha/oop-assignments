/*
    Lab 6
    Understanding the Concept of Type Conversion and Inheritance
    2.  Write two classes to store distances in meter-centimeter and feet-inch systems respectively.
        Write conversions functions so that the program can convert objects of both types.
*/

#include <iostream>

// Forward declaration of class DistanceBritish
class DistanceBritish;

class DistanceMetric
{
private:
    int _meter;
    float _centimeter;

public:
    DistanceMetric(int m = 0, float cm = 0) : _meter{m}, _centimeter{cm} {}

    // Type conversion: User-defined to user-defined
    // Overload '=' operator to convert DistanceBritish object to DistanceMetric object
    DistanceMetric operator=(DistanceBritish); // Forward declaration above needed for this declaration line

    // Specifying return type to overload '=' operator is not necessary as the compiler takes
    // the return type for operator '=' as the type of the left operand (i.e. the calling object)
    // operator=(DistanceBritish); // OK

    int getMeter() const { return _meter; }
    float getCentimeter() const { return _centimeter; }

    void display()
    {
        std::cout << _meter << "m " << _centimeter << "cm";
    }
};

class DistanceBritish
{
private:
    int _feet;
    float _inches;

public:
    DistanceBritish(int f = 0, float i = 0) : _feet{f}, _inches{i} {}

    DistanceBritish(DistanceMetric d)
    {
        float meter = d.getMeter() + d.getCentimeter() / 100.0f;
        _feet = meter * 3.28084;
        _inches = (meter * 3.28084 - _feet) * 12.0f;
    }

    int getFeet() const { return _feet; }
    float getInches() const { return _inches; }

    void display()
    {
        std::cout << _feet << "' " << _inches << "\"";
    }
};

// DistanceMetric::operator=(DistanceBritish d) // OK
DistanceMetric DistanceMetric::operator=(DistanceBritish d)
{
    float ft = d.getFeet() + d.getInches() / 12.0f;
    _meter = ft * 0.3048;
    _centimeter = (ft * 0.3048 - _meter) * 100.0f;
}

int main()
{
    DistanceMetric d1(1, 90.5);
    DistanceBritish d2(6, 3.5);

    // Convert DistanceMetric object to DistanceBritish object
    DistanceBritish d3 = d1; // d3 = DistanceBritish(d1)

    // For type conversion using operator (=) overloading, initialization and
    // assignment should be done separately
    DistanceMetric d4;
    d4 = d2;

    d1.display();
    std::cout << " = ";
    d3.display();

    std::cout << '\n';

    d2.display();
    std::cout << " = ";
    d4.display();

    return 0;
}
