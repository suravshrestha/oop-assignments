/*
    Lab 5
    Understanding the Concept of Friend Function/Class and Operator Overloading
    4.  Write a class Date that overloads prefix and postfix operators to increase the Date object by one day,
        while causing appropriate increments to the month and year (use the appropriate condition for leap year).
        The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.
*/

#include <iostream>
#include <iomanip>

class Date
{
private:
    int _year, _month, _day;

public:
    Date(int year, int month, int day) : _year{year}, _month{month}, _day{day} {}

    // Prefix increment
    Date operator++()
    {
        _day++;

        if (_day > 31)
        {
            _day = 1;
            _month++;
        }

        if (_month > 12)
        {
            _month = 1;
            _year++;
        }

        return *this;
    }

    // Postfix increment
    // int is just a dummy variable, the compiler uses the int argument to distinguish
    // between the prefix and postfix increment operators
    Date operator++(int)
    {
        Date temp(*this);
        ++*this;
        return temp;
    }

    void display()
    {
        std::cout << _year << "-"
                  << std::setfill('0') << std::setw(2) << _month << "-"
                  << std::setfill('0') << std::setw(2) << _day;
    }
};

int main()
{
    Date d(2022, 12, 31);
    d++;

    d.display();

    return 0;
}
