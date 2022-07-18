// 4. Overload function call operator

#include <iostream>

class Point
{
private:
    float _x, _y;

public:
    // Overload function call operator as a constructor
    Point operator()(float x = 0, float y = 0)
    {
        _x = x;
        _y = y;
        return *this;
    }

    void display()
    {
        std::cout << "(" << _x << ", " << _y << ")\n";
    }
};

int main()
{
    Point p1, p2;

    p1(3.5, 7.1);
    p1.display();

    p2 = p1(4, 5);
    p2.display();

    return 0;
}
