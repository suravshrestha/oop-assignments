// 7. Conversion from the meter, cm to feet, inches

#include <iostream>

using namespace std;

class BritishLength
{
private:
    int _ft, _inches;

public:
    BritishLength(int ft, int inches) : _ft(ft), _inches(inches) {}

    friend ostream &operator<<(ostream &os, const BritishLength &b)
    {
        os << b._ft << " ft " << b._inches << " inches";
        return os;
    }
};

class MetricLength
{
private:
    int _m, _cm;

public:
    MetricLength(int m, int cm) : _m(m), _cm(cm) {}

    operator BritishLength()
    {
        float feet = _m * 3.28084 + _cm * 0.0328084;
        int inches = (feet - static_cast<int>(feet)) * 12;

        return BritishLength(feet, inches);
    }

    friend ostream &operator<<(ostream &os, const MetricLength &m)
    {
        os << m._m << " m " << m._cm << " cm";
        return os;
    }
};

int main()
{
    MetricLength m(1, 93);
    BritishLength b = m;

    cout << m << " = " << b << '\n';

    return 0;
}
