/*
    Lab 4
    Additional Components of a Class
    4.  Assume that one constructor initializes data member say num_vehicles, hour, and rate.
        There should be a 10% discount if num_vehicle exceeds 10. Display the total charge.
        Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).
*/

#include <iostream>

class Fare
{
private:
    int _num_vehicles, _hour;
    float _rate;

public:
    Fare(int vehicles, int hr, float rate) : _num_vehicles{vehicles}, _hour{hr}, _rate{rate} {}

    // Copy constructor
    Fare(const Fare &f)
    {
        _num_vehicles = f._num_vehicles;
        _hour = f._hour;
        _rate = f._rate;
    }

    void displayCharge()
    {
        if (_num_vehicles > 10)
        {
            std::cout << "Total charge = " << 0.9 * _num_vehicles * _hour * _rate << '\n';
        }
        else
        {
            std::cout << "Total charge = " << _num_vehicles * _hour * _rate << '\n';
        }
    }
};

int main()
{
    Fare f1{12, 3, 100};

    // Copy object f1 to f2
    Fare f2 = f1; // Fare f2(f1);

    f2.displayCharge();

    return 0;
}
