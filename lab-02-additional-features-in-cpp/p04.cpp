/*
    Lab 2
    Additional Features in C++
    Reference variable and return by reference
    4.  Write a function that passes two temperatures by reference and sets the larger of the two numbers
        to a value entered by user by using return by reference.
*/

#include <iostream>

float &larger(float &a, float &b)
{
    // a is alias of temp1 and b is alias of temp2
    if (a > b)
    {
        return a; // return temp1
    }

    return b; // return temp2
}

int main()
{
    float temp1, temp2;

    std::cout << "Enter a temperature: ";
    std::cin >> temp1;

    std::cout << "Enter another temperature: ";
    std::cin >> temp2;

    float value; // Value entered by the user
    std::cout << "\nEnter a value: ";
    std::cin >> value;

    std::cout << "\nBefore assignment:\n";
    std::cout << "temp1 = " << temp1 << std::endl;
    std::cout << "temp2 = " << temp2 << std::endl;

    // function larger returns the reference to the larger temperature
    // larger temperature is set to value
    larger(temp1, temp2) = value;

    std::cout << "\nAfter assignment:\n";
    std::cout << "temp1 = " << temp1 << std::endl;
    std::cout << "temp2 = " << temp2 << std::endl;

    return 0;
}
