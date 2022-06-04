/*
    Lab 3
    Concept of Objects and Classes
    5.  Assume that an object represents an employee report that contains information like employee id, total bonus,
        total overtime in a particular year. Use an array of objects to represent n employees' reports.
        Write a program that displays the report. Use setPara() member function to set report attributes by passing
        the arguments and member function displayReport() to show the report according to the parameter passed.
        Display the report in the following format.
        An employee with ... has received Rs ... as a bonus and had worked ... hours as overtime in the year ...
*/

#include <iostream>

class Employee
{
private:
    int _employee_id, _total_bonus, _total_overtime, _year;

public:
    void setPara(int e_id, int bonus, int overtime, int year)
    {
        _employee_id = e_id;
        _total_bonus = bonus;
        _total_overtime = overtime;
        _year = year;
    }

    bool displayReport(int e_id)
    {
        if (_employee_id == e_id)
        {
            std::cout << "\nAn employee with employee id " << _employee_id << " has received Rs." << _total_bonus
                      << " as a bonus and had worked " << _total_overtime << " hours as overtime in the year " << _year << std::endl;

            return true;
        }

        // Employee id not found
        return false;
    }
};

int main()
{
    int num_of_employees;
    std::cout << "Enter the number of employees: ";
    std::cin >> num_of_employees;

    Employee employees[num_of_employees];

    for (int i = 0; i < num_of_employees; ++i)
    {
        std::cout << "\nEnter the data for employee " << i + 1 << std::endl;

        int employee_id, bonus, overtime, year;

        std::cout << "Employee id: ";
        std::cin >> employee_id;

        std::cout << "Total bonus: ";
        std::cin >> bonus;

        std::cout << "Total overtime: ";
        std::cin >> overtime;

        std::cout << "Enter the year: ";
        std::cin >> year;

        employees[i].setPara(employee_id, bonus, overtime, year);
    }

    int employee_id_search;
    std::cout << "\nEnter the employee id to search: ";
    std::cin >> employee_id_search;

    // for-of loop for looping through the employees
    bool employee_found = false;
    for (Employee employee : employees)
    {
        if (employee.displayReport(employee_id_search))
        {
            employee_found = true;
            break;
        }
    }

    if (!employee_found)
    {
        std::cout << "\nEmployee not found!";
    }

    return 0;
}
