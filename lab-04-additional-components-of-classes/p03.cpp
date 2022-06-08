/*
    Lab 4
    Additional Components of a Class
    3.  Write a class that can store Department ID and Department Name with constructors to
        initialize its members. Write destructor member in the same class and display the message
        "Object goes out of the scope". Your program should be made such that it should show the
        order of constructor and destructor invocation.
*/

#include <iostream>

class Department
{
private:
    std::string _department_id;
    std::string _department_name;

public:
    Department(std::string id, std::string name)
    {
        _department_id = id;
        _department_name = name;

        std::cout << "Department object created and initialized!\n";
    }

    ~Department()
    {
        std::cout << "Object goes out of the scope...Department object destroyed!\n";
    }
};

void foo()
{
    std::cout << "Start of foo\n";

    Department d{"DOECE", "Electronics and Computer Engineering"};

    std::cout << "End of foo\n";
}

int main()
{
    foo();

    return 0;
}
