/*
    Lab 7
    Understanding the Concept of Virtual Function, Virtual Base Class, and RTTI
    3.  Write a program with an abstract class Student and create derive classes
        Engineering, Medicine and Science from base class Student. Create the objects of
        the derived classes and process them and access them using an array of pointers of
        type base class Student.
*/

#include <iostream>

using namespace std;

class Student
{
public:
    virtual void print() { cout << "Student\n"; }
};

class Engineering : public Student
{
public:
    void print() override { cout << "Engineering student\n"; }
};

class Medicine : public Student
{
public:
    void print() override { cout << "Medicine student\n"; }
};

class Science : public Student
{
public:
    void print() override { cout << "Science student\n"; }
};

int main()
{
    Student *s[3];
    s[0] = new Engineering();
    s[1] = new Medicine();
    s[2] = new Science();

    s[0]->print();
    s[1]->print();
    s[2]->print();

    return 0;
}
