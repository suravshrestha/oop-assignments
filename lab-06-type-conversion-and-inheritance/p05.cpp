/*
    Lab 6
    Understanding the Concept of Type Conversion and Inheritance
    5.  Write a base class that asks the user to enter a complex number and make a derived class that
        adds the complex number of its own with the base. Finally, make a third class that is a friend of
        derived and calculate the difference of the base complex number and its own complex number.
*/

#include <iostream>

class Complex
{
protected:
    float _real, _imaginary;

public:
    Complex(float r = 0, float i = 0) : _real{r}, _imaginary{i} {}

    void prompt()
    {
        std::cout << "Enter real part: ";
        std::cin >> _real;

        std::cout << "Enter imaginary part: ";
        std::cin >> _imaginary;
    }

    void display()
    {
        std::cout << '(' << _real << ", " << _imaginary << ")\n";
    }

    friend class Complex_;
    friend class Difference;
};

class Complex_ : public Complex
{
public:
    Complex_(float r = 0, float i = 0) : Complex(r, i) {}

    Complex_ operator+(const Complex &c)
    {
        return Complex_(_real + c._real, _imaginary + c._imaginary);
    }

    friend class Difference;
};

class Difference
{
public:
    Complex result(const Complex &c1, const Complex_ &c2)
    {
        return Complex(c1._real - c2._real, c1._imaginary - c2._imaginary);
    }
};

int main()
{
    Complex c1;
    Complex_ c2;
    c1.prompt();
    std::cout << '\n';
    c2.prompt();

    std::cout << '\n';
    Complex c3 = c2 + c1;
    c3.display();

    Difference d;
    c3 = d.result(c1, c2);
    c3.display();

    return 0;
}
