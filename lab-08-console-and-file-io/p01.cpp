/*
    Lab 8
    Understanding the Concept of Console and File Input/Output
    1.  Write a program to demonstrate the use of different ios flags and functions to
        format the output. Create a program to generate the bill invoice of a department store
        by using different formatting.
*/

#include <iostream>

int main()
{
    std::cout.setf(std::ios::left);

    std::cout.width(25);
    std::cout << "Item Description";

    std::cout.setf(std::ios::right);
    std::cout.width(10);
    std::cout << "Quantity";

    std::cout.width(10);
    std::cout << "Rate";

    std::cout.width(20);
    std::cout << "Amount" << '\n'; // newline should be kept separately so that it is not counted in the 20 characters width

    std::string items[3] = {"Water", "Printed T-Shirt", "Milk"};
    float rate[3] = {1.5, 79, 4.41}; // Rate in dollars
    int quantity[3] = {5, 2, 3};

    for (int i = 0; i < 3; i++)
    {
        // std::ios::right and std::ios::left are mutually exclusive flags of std::ios::adjustfield formatting group
        // setf() only turns on the flags specified and is not smart enough to turn off other flags,
        // so to turn on only std::ios::left, we have to specify the formatting group as well

        // Turn on only std::ios::left flag, and turn off all the flags belonging to the group std::ios::adjustfield
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout.width(25);
        std::cout << items[i];

        std::cout.setf(std::ios::right);
        std::cout.width(10);
        std::cout << quantity[i];

        std::cout.setf(std::ios::fixed);
        std::cout.width(10);
        std::cout.precision(2);
        std::cout << rate[i];

        std::cout.width(20);
        std::cout << quantity[i] * rate[i] << '\n';
    }

    return 0;
}
