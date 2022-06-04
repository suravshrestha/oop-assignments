/*
    Lab 3
    Concept of Objects and Classes
    1.  Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and
        vice versa using the basic concept of class and object. Make separate classes for Celsius and
        Fahrenheit which will have the private members that hold the temperature value and make
        conversion functions in each class for conversion from one to another. For example, you
        need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and
        returns the value.
*/
#include <iostream>

/*
Member access specifiers: private, public and protected
- private members of a class are accessible only from within other members
  of the same class (or from their "friends").
- public members are accessible from anywhere the object is visible.
- protected members are accessible from their "friends",
  as well as from members of their derived classes.
*/

class Celsius
{
    // By default, all members of a class declared with the class keyword
    // have private access for all its members
    // Private members
    float _tempc;

public:
    // Constructor function has the class's name and without any return type; not even void.
    Celsius(float temp); // Constructor declaration

    // Member function definition can be included in the
    // class definition itself
    float toFahrenheit()
    {
        // Private members can only be accessed from within
        // other members of the same class
        return 9 * _tempc / 5.0f + 32;
    }

    inline float getTemp()
    {
        return _tempc;
    }
};

// Constructor definition
// It is executed everytime a new object of the class is created
Celsius::Celsius(float temp)
{
    // Assign the value to the private member _tempc
    _tempc = temp;
}

class Fahrenheit
{
private: // Specifying private is optional
    float _tempf;

public:
    // Constructor definition inside class definition
    Fahrenheit(float temp)
    {
        _tempf = temp;
    }

    float toCelsius(); // Member function declaration

    inline float getTemp()
    {
        return _tempf;
    }
};

// Member function definition (outside the class definition)
// :: is known as scope resolution operator which can be used to
// access the public members of the class
float Fahrenheit::toCelsius()
{
    return 5 * (_tempf - 32) / 9.0f;
}

int main()
{
    // In terms of variable
    // Celsius -> data type name or class name
    // c -> variable or object

    // Object or instance of the class Celsius
    Celsius c(-273.15); // Functional form initialization

    Fahrenheit f{98.6}; // Uniform initialization
    // Fahrenheit f2 = {98.6}; // Assignment initialization

    std::cout << c.getTemp() << " degree Celsius = " << c.toFahrenheit() << " degree Fahrenheit" << std::endl;
    std::cout << f.getTemp() << " degree Fahrenheit = " << f.toCelsius() << " degree Celsius" << std::endl;

    return 0;
}
