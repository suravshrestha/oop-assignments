/*
    Lab 3
    Concept of Objects and Classes
    3.  Create a class called carpark that has int data member for car id, int data member
        for charge/hour, and float data member for the parked time. Make functions to set
        data members and show the charges and parked hours of the corresponding car id.
        Make functions for setting and showing the data members.
        Member function should be called from other functions.
*/

#include <iostream>

class CarPark
{
private:
    int _car_id;
    int _charge_per_hour;
    float _parked_time;

public:
    inline void setCarId(int car_id)
    {
        _car_id = car_id;
    }

    inline void setChargePerHour(int charge_per_hour)
    {
        _charge_per_hour = charge_per_hour;
    }

    inline void setParkedTime(float parked_hours)
    {
        _parked_time = parked_hours;
    }

    inline int getChargePerHour() const
    {
        return _charge_per_hour;
    }

    inline float getParkedTime() const
    {
        return _parked_time;
    }

    void showChargePerHour()
    {
        std::cout << "Charge per hour: "
                  << "Rs." << getChargePerHour() << std::endl;
    }

    void showParkedTime()
    {
        std::cout << "Parked time: " << getParkedTime() << " hours" << std::endl;
    }

    void showTotalCharge()
    {
        std::cout << "Total charge: Rs." << getChargePerHour() * getParkedTime() << std::endl;
    }
};

int main()
{
    CarPark cp;

    cp.setCarId(1);
    cp.setParkedTime(3);
    cp.setChargePerHour(100);

    cp.showParkedTime();
    cp.showChargePerHour();
    cp.showTotalCharge();

    return 0;
}
