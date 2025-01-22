#include <iostream>
using namespace std;

// Code for Traversal in array
void display(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "  ";
    }

    cout << endl;
}

// Code for Insertion in array at any index
int index_Insertion(int array[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        array[i + 1] = array[i];
    }
    array[index] = element;
    return 1;
}

// Code for Deletion in array at any index
void index_Deletion(int array[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
}

int main()
{
    int size = 4, element = 45, index = 3, capacity = 100;

    int array[100] = {1, 2, 6, 78};

    cout << "***********Insertion***********" << endl;
    cout << "Before Insertion " << endl;
    display(array, size);

    index_Insertion(array, size, element, capacity, index);
    size += 1;
    cout << "After Insertion " << endl;
    display(array, size);

    cout << "***********Deletion***********" << endl;
    cout << "Before Deletion " << endl;
    display(array, size);

    index_Deletion(array, size, index);
    size -= 1;
    cout << "After Deletion " << endl;
    display(array, size);
    return 0;
}

// Inserting element 45 at index 3

// Array Before
// index---> 0  1  2  3
// value---> 1  2  6  78

// Array After
// index---> 0  1  2  3  4
// value---> 1  2  6  45 78

// Deleting element 45 at index 3

// Array Before
// index---> 0  1  2  3  4
// value---> 1  2  6  45 78

// Array After
// index---> 0  1  2  3
// value---> 1  2  6  78
