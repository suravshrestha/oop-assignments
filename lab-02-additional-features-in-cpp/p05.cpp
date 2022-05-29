/*
    Lab 2
    Additional Features in C++
    Inline functions
    5.  Assume that employee will have to pay 10 percent income tax to the government.
        Ask user to enter the employee salary. Use inline function to display the net
        payment to the employee by the company.
*/

#include <iostream>
#include <iomanip> // for setprecision and fixed

inline float net_salary(float salary)
{
    return 0.9 * salary;
}

int main()
{
    float salary;

    std::cout << "Enter your salary: ";
    std::cin >> salary;

    // Display two decimals
    std::cout << "\nNew salary = " << std::setprecision(2) << std::fixed
              << net_salary(salary) << std::endl;

    return 0;
}
