/*
    Lab 4
    Additional Components of a Class
    2.  Write a program that has a class with a dynamically allocated character array as its data member.
        One object should contain "Engineers are" and another should contain " Creatures of logic".
        Member function join() should concatenate two strings by passing two objects as arguments.
        Display the concatenated std::string through a member function. Use constructors to allocate and
        initialize the data member. Also, write a destructor to free the allocated memory for the
        character array. Make your own function for the concatenation of two strings.
*/

#include <iostream>
#include <cstring>

class String
{
private:
    char *_str;

private:
    // Allocate memory for the char array
    void allocateMemory()
    {
        _str = new char[strlen(_str) + 1];
    }

    // Free the allocated memory
    void freeMemory()
    {
        delete[] _str;
    }

public:
    String(const char *str)
    {
        // Convert const char * to char * as,
        // ISO C++ forbids converting a std::string constant to 'char*'
        _str = const_cast<char *>(str);
    }

    ~String()
    {
        freeMemory();
    }

    // Concatenate two strings
    void join(String s1, String s2)
    {
        allocateMemory();

        // Copy s1._str to _str of this object
        strcpy(_str, s1._str);

        // Continue copying s2._str to _str from the previous position of _str
        strcpy(_str + strlen(s1._str), s2._str);
    }

    void display()
    {
        std::cout << _str << '\n';
    }
};

int main()
{
    String s1("Engineers are");
    String s2(" Creatures of logic");

    s1.join(s1, s2);
    s1.display();

    return 0;
}
