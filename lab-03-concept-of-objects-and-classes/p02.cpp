/*
    Lab 3
    Concept of Objects and Classes
    2.  Assume that you want to check whether the number is prime or not. Write a program that asks for
        numbers repeatedly. When it finishes checking a number the program asks if the user wants to do
        another calculation. The response can be 'y' or 'n'. Don't forget to use the object-oriented concept.
*/

#include <iostream>

class Number
{
private:
    int _num;

public:
    void setValue(int num)
    {
        _num = num;
    }

    int getValue()
    {
        return _num;
    }

    bool isPrime()
    {
        int factors = 2;

        for (int i = 2; i < _num; ++i)
        {
            if (_num % i == 0)
            {
                return false;
            }
        }

        if (factors == 2)
        {
            return true;
        }
    }
};

int main()
{
    Number n;

    while (true)
    {
        int num;
        std::cout << "Enter a number: ";
        std::cin >> num;

        if (num == 1)
        {
            std::cout << "1 is neither prime nor composite\n";
        }
        else
        {
            n.setValue(num);

            if (n.isPrime())
            {
                std::cout << n.getValue() << " is a prime number\n";
            }
            else
            {
                std::cout << n.getValue() << " is a composite number\n";
            }
        }

        char option;
        std::cout << "\nDo you want to continue entering numbers? (y/n): ";
        std::cin >> option;

        if (option == 'n' || option == 'N')
        {
            break;
        }

        std::cout << '\n';
    }

    return 0;
}
