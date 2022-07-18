// 6. Overload bitwise operators

#include <iostream>

class Integer
{
private:
    int _val;

public:
    Integer(int val = 0) : _val{val} {}

    // Overload bitwise AND operator
    int operator&(const Integer &i)
    {
        return _val & i._val;
    }

    // Overload bitwise OR operator
    int operator|(const Integer &i)
    {
        return _val | i._val;
    }

    // Overload bitwise NOT operator
    int operator~()
    {
        return ~_val;
    }

    // Overload bitwise XOR operator
    int operator^(const Integer &i)
    {
        return _val ^ i._val;
    }

    // Overload bitwise left shift operator
    int operator<<(int num)
    {
        return _val << num;
    }

    // Overload bitwise right shift operator
    int operator>>(int num)
    {
        return _val >> num;
    }
};

int main()
{
    Integer a(12), b(25);

    std::cout << "a & b = " << (a & b) << '\n';
    std::cout << "a | b = " << (a | b) << '\n';
    std::cout << "~a = " << (~a) << '\n';
    std::cout << "a ^ b = " << (a ^ b) << '\n';
    std::cout << "a << 2 = " << (a << 2) << '\n';
    std::cout << "a >> 3 = " << (a >> 3);

    return 0;
}
