/*
    Lab 8
    Understanding the Concept of Console and File Input/Output
    3.  Write a program to overload stream operators to read a complex number and
        display the complex number in a + ib format.
*/

#include <iostream>

class Complex
{
private:
    float _a, _b;

public:
    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
    friend std::istream &operator>>(std::istream &is, Complex &c);
};

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    os << c._a << " + " << c._b << "i";
    os << std::flush;
    return os;
}

std::istream &operator>>(std::istream &is, Complex &c)
{
    is >> c._a >> c._b;
    return is;
}

int main()
{
    Complex c;
    std::cin >> c;
    std::cout << c << '\n';

    return 0;
}
