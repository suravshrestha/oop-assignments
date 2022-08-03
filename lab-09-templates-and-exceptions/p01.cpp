/*
    Lab 9
    Understanding the Concept of Templates and Exceptions
    1.  Create a function called sum() that returns the sum of the elements of an array.
        Make this function into a template so it will work with any numerical type.
        Write a program that applies this function to data of various types.
*/

#include <iostream>

// Function template
template <class T>
T sum(T arr[], int size)
{
    T sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << sum(arr1, 5) << '\n';
    std::cout << sum(arr2, 5) << '\n';

    return 0;
}
