// 3. Overload assignment operator

#include <iostream>

class Fraction
{
private:
    int _numerator, _denominator;

public:
    Fraction(int numerator = 0, int denominator = 1)
        : _numerator{numerator}, _denominator{denominator}
    {
        if (denominator == 0)
        {
            std::cout << "Denominator cannot be zero!" << '\n';
        }
    }

    // Overloaded assignment operator
    Fraction &operator=(const Fraction &fraction)
    {
        // Copy the members
        _numerator = fraction._numerator;
        _denominator = fraction._denominator;

        // Return the existing object so we can chain this operator
        return *this;
    }

    void display()
    {
        std::cout << _numerator << "/" << _denominator << '\n';
    }
};

int main()
{
    Fraction fiveThirds{5, 3};
    Fraction f;
    f = fiveThirds; // Call overloaded assignment

    Fraction f1{5, 3}, f2{7, 2}, f3{9, 5};

    f1 = f2 = f3; // chained assignment

    f.display();
    f1.display();
    f2.display();
    f3.display();

    return 0;
}
