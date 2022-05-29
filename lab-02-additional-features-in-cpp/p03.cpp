/*
    Lab 2
    Additional Features in C++
    Namespaces
    3.  Define two namespaces: Square and Cube. In both the namespaces, define an integer variable named "num" and a function named "foo".
        The "foo" function in "Square" namespace, should return the square of an integer passed as an argument while the "foo" function in
        "Cube" namespace, should return the cube of an integer passed as an argument. In the main function, set the integer variables "num"
        of both the namespaces with different values. Then, compute and print the cube of the integer variable "num" of the "Square" namespace
        using the "foo" function of the "Cube" namespace and the square of the integer variable "num" of the "Cube" namespace using the
        "foo" function of the "Square" namespace.
*/

#include <iostream>

namespace Square
{
    int num;

    int foo(int num)
    {
        return num * num;
    }
}

namespace Cube
{
    int num;

    int foo(int num)
    {
        return num * num * num;
    }
}

int main()
{
    // Access variable using scope resolution operator (::)
    // Syntax: namespace_name::identifier
    Square::num = 5;
    Cube::num = 7;

    // ::foo is used to access the function of the respective namespace
    std::cout << Square::num << "^2 = " << Square::foo(Square::num) << std::endl;
    std::cout << Cube::num << "^3 = " << Cube::foo(Cube::num) << std::endl;

    return 0;
}
