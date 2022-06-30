/*
    Lab 5
    Understanding the Concept of Friend Function/Class and Operator Overloading
    3.  Write a program to compare two objects of a class that contains an integer value as its data member.
        Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=),
        greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.
*/

#include <iostream>

class Integer
{
private:
    int _val;

public:
    Integer(int val) : _val{val} {}

    bool operator==(const Integer &i)
    {
        return _val == i._val;
    }

    bool operator<(const Integer &i)
    {
        return _val < i._val;
    }

    bool operator>(const Integer &i)
    {
        return _val > i._val;
    }

    bool operator!=(const Integer &i)
    {
        return _val != i._val;
    }

    bool operator<=(const Integer &i)
    {
        return _val <= i._val;
    }

    bool operator>=(const Integer &i)
    {
        return _val >= i._val;
    }
};

int main()
{
    Integer i1(1), i2(2);

    // (i1 == i2) is equivalent to (i1.operator==(i2))
    std::cout << "i1 == i2 -> " << ((i1 == i2) ? "true" : "false") << '\n';
    std::cout << "i1 < i2 -> " << ((i1 < i2) ? "true" : "false") << '\n';
    std::cout << "i1 > i2 -> " << ((i1 > i2) ? "true" : "false") << '\n';
    std::cout << "i1 != i2 -> " << ((i1 != i2) ? "true" : "false") << '\n';
    std::cout << "i1 <= i2 -> " << ((i1 <= i2) ? "true" : "false") << '\n';
    std::cout << "i1 >= i2 -> " << ((i1 >= i2) ? "true" : "false") << '\n';

    return 0;
}
