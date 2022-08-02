// 3. Conversion from meter system to feet system.

#include <iostream>

using namespace std;

class Feet
{
private:
    float _value;

public:
    Feet(float feet) : _value(feet) {}

    float getValue() const { return _value; }
};

class Meter
{
private:
    float _value;

public:
    Meter(float meter) : _value(meter) {}

    operator Feet()
    {
        return Feet(_value * 3.28084);
    }

    float getValue() const { return _value; }
};

int main()
{
    Meter m(1);
    Feet f = m;

    cout << m.getValue() << " m = " << f.getValue() << " ft\n";

    return 0;
}
