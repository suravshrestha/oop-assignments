// 2. Conversion from Cartesian coordinate to the polar coordinate system.

#include <iostream>
#include <cmath>

using namespace std;

class Polar
{
private:
    float _r, _theta;

public:
    Polar(float r, float theta) : _r(r), _theta(theta) {}

    // Overload insertion operator to print the object
    friend ostream &operator<<(ostream &os, const Polar &pt)
    {
        os << "(" << pt._r << ", " << pt._theta << ")";
        return os;
    }
};

class Cartesian
{
private:
    float _x, _y;

public:
    Cartesian(float x, float y) : _x(x), _y(y) {}

    operator Polar()
    {
        return Polar(sqrt(_x * _x + _y * _y), atan2(_y, _x));
    }

    friend ostream &operator<<(ostream &os, const Cartesian &pt)
    {
        return os << "(" << pt._x << ", " << pt._y << ")";
    }
};

int main()
{
    Cartesian c(3, 4);
    Polar p = c;

    cout << c << " = " << p << '\n';

    return 0;
}
