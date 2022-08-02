// 4. Conversion from the 24-hour clock to 12 hour

#include <iostream>

using namespace std;

class Clock12Hour
{
private:
    int _hr, _min, _sec;

public:
    Clock12Hour(int hr, int min, int sec) : _hr(hr), _min(min), _sec(sec) {}

    friend ostream &operator<<(ostream &os, const Clock12Hour &c)
    {
        os << c._hr << ":" << c._min << ":" << c._sec;
        return os;
    }
};

class Clock24Hour
{
private:
    int _hr, _min, _sec;

public:
    Clock24Hour(int hr, int min, int sec) : _hr(hr), _min(min), _sec(sec) {}

    operator Clock12Hour()
    {
        return Clock12Hour((_hr > 12) ? (_hr - 12) : _hr, _min, _sec);
    }

    friend ostream &operator<<(ostream &os, const Clock24Hour &c)
    {
        os << c._hr << ":" << c._min << ":" << c._sec;
        return os;
    }
};

int main()
{
    Clock24Hour c1(13, 14, 15);
    Clock12Hour c2 = c1;

    cout << c1 << " = " << c2 << '\n';

    return 0;
}
