// 6. Conversion from the pound, ounce to kg, gm

#include <iostream>

using namespace std;

class MetricMass
{
private:
    int _kg, _gm;

public:
    MetricMass(int kg, int gm) : _kg(kg), _gm(gm) {}

    friend ostream &operator<<(ostream &os, const MetricMass &m)
    {
        os << m._kg << " kg " << m._gm << " gm";
        return os;
    }
};

class BritishMass
{
private:
    int _pound, _ounce;

public:
    BritishMass(int pound, int ounce) : _pound(pound), _ounce(ounce) {}

    operator MetricMass()
    {
        float kg = _pound * 0.453592 + _ounce * 0.0283495;
        int gm = (kg - static_cast<int>(kg)) * 1000;

        return MetricMass(kg, gm);
    }

    friend ostream &operator<<(ostream &os, const BritishMass &m)
    {
        os << m._pound << " pound " << m._ounce << " ounce";
        return os;
    }
};

int main()
{
    BritishMass m1(70, 16);
    MetricMass m2 = m1;

    cout << m1 << " = " << m2 << '\n';

    return 0;
}
