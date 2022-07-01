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

        if (
            // Month 1, 3, 5, 7, 8, 10, 12 has 31 days
            ((_month == 1 || _month == 3 || _month == 5 || _month == 7 ||
              _month == 8 || _month == 10 || _month == 12) &&
             (_day > 31)) ||

            // Month 4, 6, 9, 11 has 30 days
            ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && (_day > 30)) ||

            // Month 2 in leap year has 29 days
            (isLeapYear() && (_month == 2 && _day > 29)) ||

            // Month 2 in non-leap year has 28 days
            (!isLeapYear() && (_month == 2 && _day > 28)))
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

    bool isLeapYear()
    {
        // If the year is divisible by 400, then it is a leap year
        if (_year % 400 == 0)
            return true;

        // else if the year is divisible by 100, then it is not a leap year
        if (_year % 100 == 0)
            return false;

        // else if the year is divisible by 4, then it is a leap year
        if (_year % 4 == 0)
            return true;

        return false;
    }

    void display()
    {
        std::cout << _year << "-"
                  << std::setfill('0') << std::setw(2) << _month << "-"
                  << std::setfill('0') << std::setw(2) << _day << '\n';
    }
};

int main()
{
    Date d1(2022, 12, 31);
    d1.display();

    // First assign d1 to d2 and then increase d1
    Date d2 = d1++;
    d2.display();
    d1.display();

    // Assign the increased value to d1
    d1 = ++d1;
    d1.display();

    return 0;
}
