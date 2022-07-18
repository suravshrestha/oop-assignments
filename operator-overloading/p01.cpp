// 1. Overload subscript operator

#include <iostream>

class IntList
{
private:
    // The braces will initialize the values to 0
    // If we don't use braces then the values will be initialized to garbage
    int _integers[10]{};

public:
    // Overload the subscript operator ([])
    // It allows us to both get and set values of _integers directly
    int &operator[](int index)
    {
        return _integers[index];
    }
};

int main()
{
    IntList list;

    // Set value
    list[2] = 3;

    // Get value
    std::cout << list[2] << '\n';
    std::cout << list[3] << '\n';

    return 0;
}
