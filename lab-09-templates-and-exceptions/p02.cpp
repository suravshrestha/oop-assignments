/*
    Lab 9
    Understanding the Concept of Templates and Exceptions
    2.  Write a class template for queue class. Assume the programmer using the queue won't make mistakes,
        like exceeding the capacity of the queue or trying to remove an item when the queue is empty.
        Define several queues of different item types and insert and remove item from them.
*/

#include <iostream>

template <class T>
class Queue
{
private:
    T *queue;
    int front, back;

public:
    Queue(int capacity)
    {
        front = 0;
        back = -1;
        queue = new T[capacity];
    }

    ~Queue()
    {
        delete[] queue;
    }

    // Inserts an element to the back of the queue
    void enqueue(T item)
    {
        queue[++back] = item;
    }

    // Removes an element from the front of the queue and returns it
    T dequeue();
};

// Class template member function defintion outside the class
template <class T>
T Queue<T>::dequeue()
{
    return queue[front++];
}

int main()
{
    Queue<int> q(3);

    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(3);

    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';

    return 0;
}
