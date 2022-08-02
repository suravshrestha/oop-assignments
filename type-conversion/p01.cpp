// 1. Conversion from Kg to pound system.

#include <iostream>

using namespace std;

class Pound
{
private:
    float _value;

public:
    Pound(float pound) : _value(pound) {}

    float getValue() const { return _value; }
};

class Kilogram
{
private:
    float _value;

public:
    Kilogram(float kg) : _value(kg) {}

    operator Pound()
    {
        return Pound(_value * 2.20462);
    }

    float getValue() const { return _value; }
};

int main()
{
    Kilogram wt1(70);
    Pound wt2 = wt1;

    cout << wt1.getValue() << " kg = " << wt2.getValue() << " pound\n";

    return 0;
}
