#include <iostream>
#include <climits>
using namespace std;
class CountSort
{
public:
    void printArray(int *A, int n);
    int maximum(int A[], int n);
    void countSort(int *A, int n);
};

void CountSort::printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << A[i];
    }
    cout << endl;
}

int CountSort::maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void CountSort::countSort(int *A, int n)
{
    // Find the maximum element in A
    int maxi = maximum(A, n);
    int i, j;

    int *count = new int[maxi + 1];
    // Create the count Array
    for (int i = 0; i < maxi + 1; i++)
    {
        // Initialize the array element to 0
        count[i] = 0;
    }
    // Incrementing the corresponding index in the count array
    for (int i = 0; i < n; i++)
    {

        count[A[i]] = count[A[i]] + 1;
    }
    i = 0; // Counter for count array
    j = 0; // Counter for given array A

    while (i <= maxi)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    CountSort Object;
    int A[] = {3,1,9,7,1,2,4};
    int n = 7;
    cout << "********Unsorted Array********" << endl;
    Object.printArray(A, n);
    Object.countSort(A, n);
    cout << endl
         << "********Sorted Array********" << endl;
    Object.printArray(A, n);
    cout << "Count sort is not Adaptive means for Sorted Array also it will take O(m+n) Time complexity but it is Stable" << endl
         << endl
         << "Count sort Time Complexity in O(n) or O(m+n)" << endl
         << "Drawback of Count sort  is ,if the maximum value of array '100' and size of array is 7 then it will create the Count array of size 100" << endl;
    return 0;
}

// Count Sort:::: Time Complexity is O(m + n)  => O(n) but ExtraSpace is used
// Fastest Sorting Algorithm

// Unsorted Array::
// index---> 0  1   2  3  4   5  6
// value---> 3  1   9  7  1   2  4              //Maximum value in Unsorted Array is 9
//                  ^                           //Size of Unsorted Array is 7
//                  |
//               maximum value
//
// Count Array::
// index---> 0  1   2  3  4   5  6  7  8  9                //Initially all elements of array are 0
// value---> 0  0   0  0  0   0  0  0  0  0               //Size of Unsorted Array is Maximum + 1 = 9 + 1 = 10
//
// index---> 0  1   2  3  4   5  6
// value---> 3  1   9  7  1   2  4
//           ^                                          // Incrementing the value by 1 in index 3 of Count Array
//           |
//           i
//
// Count Array::
// index---> 0  1   2  3*  4   5  6  7  8  9
// value---> 0  0   0  1   0   0  0  0  0  0
//

// index---> 0  1   2  3  4   5  6
// value---> 3  1   9  7  1   2  4                   // Incrementing the value by 1 in index 1 of Count Array
//              ^
//              |
//              i
//
// Count Array::
// index---> 0  1*   2  3*  4   5  6  7  8  9
// value---> 0  1    0  1   0   0  0  0  0  0
//

// index---> 0  1   2  3  4   5  6
// value---> 3  1   9  7  1   2  4                     // Incrementing the value by 1 in index 9 of Count Array
//                  ^
//                  |
//                  i
//
// Count Array::
// index---> 0  1*   2  3*  4   5  6  7  8  9*
// value---> 0  1    0  1   0   0  0  0  0  1
//
//
// index---> 0  1   2  3  4   5  6
// value---> 3  1   9  7  1   2  4                     // Incrementing the value by 1 in index 7 of Count Array
//                     ^
//                     |
//                     i
//
// Count Array::
// index---> 0  1*   2  3*  4   5  6  7*  8  9*
// value---> 0  1    0  1   0   0  0  1   0  1
//
//
//
// index---> 0  1   2  3  4   5  6
// value---> 3  1   9  7  1   2  4                     // Incrementing the value by 1 in index 1 of Count Array
//                        ^
//                        |
//                        i
//
// Count Array::
// index---> 0  1**   2  3*  4   5  6  7*  8  9*
// value---> 0  2     0  1   0   0  0  1   0  1
//
// index---> 0  1   2  3  4   5  6
// value---> 3  1   9  7  1   2  4                     // Incrementing the value by 1 in index 2 of Count Array
//                            ^
//                            |
//                            i
//
// Count Array::
// index---> 0  1**   2*  3*  4   5  6  7*  8  9*
// value---> 0  2     1   1   0   0  0  1   0  1
//
// index---> 0  1   2  3  4   5  6
// value---> 3  1   9  7  1   2  4                     // Incrementing the value by 1 in index 4 of Count Array
//                               ^
//                               |
//                               i
// Count Array::
// index---> 0  1**   2*  3*  4*   5  6  7*  8  9*
// value---> 0  2     1   1   1    0  0  1   0  1
//
// index---> 0  1   2  3  4   5  6
// value---> 1                                           // Decrementing the value by 1 in index 1 of Count Array
//           ^                                          // Now filling the Unsorted array using  Count array
//           |
//           i
//
// Count Array::
// index---> 0  1*   2*  3*  4*   5  6  7*  8  9*
// value---> 0  1    1   1   1    0  0  1   0  1
//
// index---> 0  1   2  3  4   5  6
// value---> 1  1                                         // Decrementing the value by 1 in index 1 of Count Array
//              ^
//              |
//              i

// Count Array::
// index---> 0  1   2*  3*  4*   5  6  7*  8  9*
// value---> 0  0   1   1   1    0  0  1   0  1

// index---> 0  1   2  3  4   5  6
// value---> 1  1   2                                      // Decrementing the value by 1 in index 2 of Count Array
//                  ^
//                  |
//                  i
// Count Array::
// index---> 0  1   2  3*  4*   5  6  7*  8  9*
// value---> 0  0   0  1   1    0  0  1   0  1

// index---> 0  1   2  3  4   5  6
// value---> 1  1   2  3                                   // Decrementing the value by 1 in index 3 of Count Array
//                     ^
//                     |
//                     i
// Count Array::
// index---> 0  1   2  3  4*  5  6  7*  8  9*
// value---> 0  0   0  0  1   0  0  1   0  1

// index---> 0  1   2  3  4   5  6
// value---> 1  1   2  3  4                                 // Decrementing the value by 1 in index 4 of Count Array
//                        ^
//                        |
//                        i

// Count Array::
// index---> 0  1   2  3  4   5  6  7*  8  9*
// value---> 0  0   0  0  0   0  0  1   0  1

// index---> 0  1   2  3  4   5  6
// value---> 1  1   2  3  4   7                                // Decrementing the value by 1 in index 7 of Count Array
//                            ^
//                            |
//                            i

// Count Array::
// index---> 0  1   2  3  4   5  6  7  8  9
// value---> 0  0   0  0  0   0  0  0  0  1

// index---> 0  1   2  3  4   5  6
// value---> 1  1   2  3  4   7  9                             // Decrementing the value by 1 in index 9 of Count Array
//                               ^
//                               |
//                               i
// Count Array::
// index---> 0  1   2  3  4   5  6  7  8  9                //Finally all elements of array are 0
// value---> 0  0   0  0  0   0  0  0  0  0

// Sorted Array::
// index---> 0  1   2  3  4   5  6
// value---> 1  1   2  3  4   7  9             //Maximum value in Sorted Array is 9
//                                            // Size of Sorted Array is 7

// Drawback of Count sort  is ,if the maximum value of array "100" and size of array is 7 then it will create the Count array of size 100
