#include <iostream>
#include <functional> //Header file for function object
#include <algorithm>
using namespace std;

int main()
{
    cout << "******************************Function Object in STL (Functors) ******************************" << endl
         << endl;
    cout << "Creating the array of : 1  9   4   12  54  77  3 " << endl;
    int arr[] = {1, 9, 4, 12, 54, 77, 3};

    cout << endl
         << "Displaying the element of array Before sorting" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << "     ";
    }

    cout << endl
         << endl
         << "Sorting the first 4 element of array of : 1  9   4   12  54  77  3   " << endl;
    sort(arr, arr + 4);

    cout << endl
         << "Displaying the element of array After sorting::" << endl;
    cout << "Asending order----->    |" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << "     ";
    }

    cout << endl
         << endl
         << "54 77 3 are not sorted, sort is done for only first 4 element " << endl
         << endl;

    cout << "sort() Method which takes Objects , means we are passing object inside sort method " << endl;
    cout << "greater<int>() and less<int>() are Function Objects means object which is passed in sort() Method" << endl
         << endl;

    cout << "******Before Using Function Object::******" << endl
         << endl;

    cout << "Creating the array2 of : 1, 73,  4,  2,  54,  7,  30 " << endl;

    int arr2[] = {1, 73, 4, 2, 54, 7, 30};

    cout << endl
         << "Displaying the element of array Before sorting" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr2[i] << "     ";
    }

    cout << endl
         << endl
         << "Sorting the all element of array2 of : 1, 73,  4,  2,  54,  7,  30   " << endl;
    sort(arr2, arr2 + 7);

    cout << endl
         << "Displaying the element of array After sorting::" << endl;
    cout << "Asending order----->    " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr2[i] << "     ";
    }

    sort(arr2, arr2 + 7, greater<int>());
    cout << endl
         << endl
         << "******After Using Function Object:: sort() method takes greater<int>() object ,as 3rd argument******" << endl
         << endl;
    cout << "greater<int>() object is making the sorted array in Desending order" << endl;
    cout << endl
         << "Displaying the element of array2 After sorting::" << endl;
    cout << "Desending order----->    " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr2[i] << "     ";
    }

    sort(arr2, arr2 + 7, less<int>());
    cout << endl
         << endl
         << "******After Using Function Object:: sort() method takes less<int>() object ,as 3rd argument******" << endl;
    cout << "less<int>() object is making the sorted array in Asending order" << endl;
    cout << endl
         << "Displaying the element of array2 After sorting::" << endl;
    cout << "Asending order----->    " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr2[i] << "     ";
    }

    return 0;
}

// Function Object are also called Functors
// Function Object: Function wrapped in a class so that it available like an object
// function are used as object  ---> function object
//
// class ----> inside member function ---> called then something happend ---> () operator---->{going to overlload }