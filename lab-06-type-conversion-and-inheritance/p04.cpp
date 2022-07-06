/*
    Lab 6
    Understanding the Concept of Type Conversion and Inheritance
    4.  Write three derived classes inheriting functionality of base class person (should have a member function that
        asks to enter name and age) and with added unique features of student, and employee, and functionality to assign,
        change and delete records of student and employee. And make one member function for printing the address of the
        objects of classes (base and derived) using this pointer. Create two objects of the base class and derived classes
        each and print the addresses of individual objects. Using a calculator, calculate the address space occupied by
        each object and verify this with address spaces printed by the program.
*/

#include <iostream>
#include <cstring>

class Person
{
protected:
    char _name[100];
    int _age;

public:
    Person()
    {
        fflush(stdin);
        std::cout << "Name: ";
        gets(_name);

        std::cout << "Age: ";
        std::cin >> _age;
    }

    void setDetails(const char name[], int age)
    {
        strcpy(_name, name);
        _age = age;
    }

    void display()
    {
        std::cout << "\nName: " << _name << '\n';
        std::cout << "Age: " << _age << '\n';
    }

    void displayAddress()
    {
        std::cout << "Address of this object: " << this << '\n';
    }

    void deleteObject()
    {
        delete this;
    }
};

class Student : public Person
{
private:
    char _id[20];

public:
    Student()
    {
        // First, the most-base class (at the top of the inheritance tree) is constructed first. Then each child class is
        // constructed in order, until the most-child class (at the bottom of the inheritance tree) is constructed last.
        // which is logical due to the fact that, "A child can not exist without a parent"

        // Person class is constructed first and then only Student class is constructed.

        fflush(stdin);
        std::cout << "Id: ";
        gets(_id);
    }

    void setDetails(const char name[], int age, const char id[])
    {
        Person::setDetails(name, age);
        strcpy(_id, id);
    }

    void display()
    {
        std::cout << "\nStudent details:";

        Person::display();
        std::cout << "Id: " << _id << '\n';
    }
};

class Employee : public Person
{
private:
    char _id[20];
    int _salary;

public:
    Employee()
    {
        fflush(stdin);
        std::cout << "Id: ";
        gets(_id);

        std::cout << "Salary: ";
        std::cin >> _salary;
    }

    void setDetails(const char name[], int age, const char id[], int salary)
    {
        Person::setDetails(name, age);
        strcpy(_id, id);
        _salary = salary;
    }

    void display()
    {
        std::cout << "\nEmployee details:";

        Person::display();
        std::cout << "Id: " << _id << '\n';
        std::cout << "Salary: " << _salary << '\n';
    }
};

int main()
{
    std::cout << "Enter details for person:\n";
    Person p;
    p.display();
    p.displayAddress();
    p.setDetails("John", 30);
    p.display();

    std::cout << "\nEnter details for student:\n";
    Student s;
    s.display();
    s.displayAddress();
    s.setDetails("Jane", 32, "bct089");
    s.display();

    std::cout << "\nEnter details for employee:\n";
    Employee e;
    e.display();
    e.displayAddress();
    e.setDetails("Janet", 35, "janet89", 10000);
    e.display();

    p.deleteObject();
    s.deleteObject();
    e.deleteObject();

    return 0;
}
