/*
    Lab 9
    Understanding the Concept of Templates and Exceptions
    3.  Modify the stack class given in the previous lab to add the exception when a user tries
        to add an item while the stack is full and when the user tries to remove an item while the
        stack is empty. Throw exceptions in both of the cases and handle these exceptions.
*/

#include <iostream>

class Stack
{
private:
    int *arr;
    int top, size;

public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int item)
    {
        try
        {
            if (top + 1 == size)
            {
                throw "Stack is full!";
            }

            // This line is not executed if the exception is raised
            arr[++top] = item;
        }
        catch (const char *e)
        {
            // This block is executed if the above stack overflow error is raised
            std::cerr << "Error: " << e << '\n';
        }
    }

    int pop()
    {
        try
        {
            if (top == -1)
            {
                throw "Stack is empty!";
            }

            return arr[top--];
        }
        catch (const char *e)
        {
            std::cerr << "Error: " << e << '\n';
        }
    }
};

int main()
{
    Stack s(2);

    s.pop();

    s.push(1);
    s.push(7);

    s.push(4);

    return 0;
}
