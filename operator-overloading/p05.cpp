// 5. Overload logical operators

#include <iostream>

class Integer
{
private:
    int _val;

public:
    Integer(int val = 0) : _val{val} {}

    bool operator==(const Integer &i)
    {
        return _val == i._val;
    }

    bool operator<(const Integer &i)
    {
        return _val < i._val;
    }

    bool operator>(const Integer &i)
    {
        return _val > i._val;
    }

    bool operator!=(const Integer &i)
    {
        return _val != i._val;
    }

    bool operator<=(const Integer &i)
    {
        return _val <= i._val;
    }

    bool operator>=(const Integer &i)
    {
        return _val >= i._val;
    }
};

int main()
{
    Integer i1(1), i2(2);

    // (i1 == i2) is equivalent to (i1.operator==(i2))
    std::cout << "i1 == i2 -> " << ((i1 == i2) ? "true" : "false") << '\n';
    std::cout << "i1 < i2 -> " << ((i1 < i2) ? "true" : "false") << '\n';
    std::cout << "i1 > i2 -> " << ((i1 > i2) ? "true" : "false") << '\n';
    std::cout << "i1 != i2 -> " << ((i1 != i2) ? "true" : "false") << '\n';
    std::cout << "i1 <= i2 -> " << ((i1 <= i2) ? "true" : "false") << '\n';
    std::cout << "i1 >= i2 -> " << ((i1 >= i2) ? "true" : "false");

    return 0;
}
