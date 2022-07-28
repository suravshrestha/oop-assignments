/*
    Lab 8
    Understanding the Concept of Console and File Input/Output
    2.  Write a program to create a user-defined manipulator that will format the output by
        setting the width, precision, and fill character at the same time by passing arguments.
*/

#include <iostream>
#include <iomanip>

class Manipulator
{
private:
    int _width, _precision;
    char _fill_char;

public:
    Manipulator(int width, int precision, char fill_char) : _width{width}, _precision{precision}, _fill_char{fill_char} {}

    // Overload the insertion operator (<<) to format the output for this class's object
    friend std::ostream &operator<<(std::ostream &os, const Manipulator &m);
};

std::ostream &operator<<(std::ostream &os, const Manipulator &m)
{
    os << std::setw(m._width) << std::fixed << std::setprecision(m._precision) << std::setfill(m._fill_char);
    os << std::flush;

    return os;
}

Manipulator wpf(int width, int precision, char fill)
{
    return Manipulator(width, precision, fill);
}

int main()
{
    std::cout << 123.5 << ' ' << wpf(10, 5, '*') << 123.456 << '\n';

    return 0;
}
