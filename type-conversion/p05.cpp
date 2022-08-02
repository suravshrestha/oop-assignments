// 5. Conversion from liter to gallons

#include <iostream>

using namespace std;

class Gallon
{
private:
    float _value;

public:
    Gallon(float g) : _value(g) {}

    float getValue() const { return _value; }
};

class Liter
{
private:
    float _value;

public:
    Liter(float l) : _value(l) {}

    operator Gallon()
    {
        return Gallon(_value * 0.264172);
    }

    float getValue() const { return _value; }
};

int main()
{
    Liter l(1);
    Gallon g = l;

    cout << l.getValue() << " L = " << g.getValue() << " gal\n";

    return 0;
}
