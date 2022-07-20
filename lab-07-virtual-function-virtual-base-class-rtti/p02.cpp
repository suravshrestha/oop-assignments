/*
    Lab 7
    Understanding the Concept of Virtual Function, Virtual Base Class, and RTTI
    2.  Create a class Person and two derived classes Employee and Student, inherited from
        class Person. Now create a class Manager which is derived from two base classes
        Employee and Student. Show the use of the virtual base class.
*/

#include <iostream>

class Person
{
public:
    Person(int foo)
    {
        std::cout << "Calling Person() " << foo << '\n';
    }
};

// Person is made virtual base class
class Employee : virtual public Person
{
public:
    // When creating an instance of Manager, the virtual base class constructor call from Employee constructor is ignored.
    // Here, Person constructor will be called only while creating an instance of Employee
    Employee(int bar) : Person(bar)
    {
        std::cout << "Calling Employee() " << bar << '\n';
    }
};

class Student : virtual public Person
{
public:
    Student(int baz) : Person(baz)
    {
        std::cout << "Calling Student() " << baz << '\n';
    }
};

class Manager : public Employee, public Student
{
public:
    // If a class inherits one or more classes that have virtual parents,
    // the most derived class is responsible for constructing the virtual base class.
    // So, Person constructor is called from here if Manager object is created
    Manager(int foo, int bar, int baz) : Person(foo), Employee(bar), Student(baz)
    {
        std::cout << "Calling Manager() " << foo << '\n';
    }
};

int main()
{
    Manager m{3, 5, 7};

    return 0;
}
