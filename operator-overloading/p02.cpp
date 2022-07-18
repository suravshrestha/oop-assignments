// 2. Overload new and delete operator

#include <iostream>

class Point
{
private:
    float _x{0}, _y{0};

public:
    Point(float x, float y) : _x{x}, _y{y} {}

    void *operator new(size_t size)
    {
        std::cout << "new operator called\n";
        void *p = malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        std::cout << "delete operator called\n";
        ::delete (Point *)p; // Global scope resolution is to avoid recursion
    }

    void display()
    {
        std::cout << "(" << _x << ", " << _y << ")\n";
    }
};

int main()
{
    Point *p = new Point(3.5, 7.1);

    p->display();

    delete p;

    // Dummy result as a is deleted in the above line
    // p->display();

    return 0;
}
