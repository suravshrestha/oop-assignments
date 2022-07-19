// 2. Overload new and delete operator

#include <iostream>

class Point
{
private:
    float _x, _y;

public:
    Point(float x = 0, float y = 0) : _x{x}, _y{y} {}

    void *operator new(size_t size)
    {
        std::cout << "new operator called\n";
        void *p = malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        std::cout << "delete operator called\n";

        // Deleting void* is undefined so we typecast it to Point*
        // Global scope resolution is to avoid recursion
        ::delete (Point *)p;
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
