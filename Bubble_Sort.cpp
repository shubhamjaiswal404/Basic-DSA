#include <iostream>
using namespace std;
class BubbleSort
{
public:
    void printArray(int *A, int n);
    void bubbleSort(int *A, int n);
    void bubbleSort_Adaptive(int *A, int n);
};

void BubbleSort::printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << A[i];
    }
    cout << endl;
}

void BubbleSort::bubbleSort(int *A, int n)
{
    int isSorted = 0; // not Sorted Array take this
    int temp;
    for (int i = 0; i < n - 1; i++)
    { // for number of passes
        cout << "Working on pass number " << i + 1 << " , Number of Comparisons take place is  " << n - i - 1 << endl;
        if (isSorted)
        {
            break;
        }
        for (int j = 0; j < n - 1 - i; j++)
        { // for number of comparison in each pass
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void BubbleSort::bubbleSort_Adaptive(int *A, int n)
{
    int isSorted = 1; // Sorted Array take this
    int temp;
    for (int i = 0; i < n - 1; i++)
    { // for number of passes
        cout << "Working on pass number " << i + 1 << " , Number of Comparisons take place is  " << n - i - 1 << endl;
        if (isSorted)
        {
            break;
        }
        for (int j = 0; j < n - 1 - i; j++)
        { // for number of comparison in each pass
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}


int main()
{
    BubbleSort Object;
    int A[] = {7, 11, 9, 2, 17, 4};
    int n = 6;
    // isSorted =0  not Sorted Array take this
    cout << "********Unsorted Array********" << endl;
    Object.printArray(A, n); // Printing the array before sorting
    cout << endl;
    Object.bubbleSort(A, n); // Function to sort the array
    cout << endl
         << "********Sorted Array********" << endl;
    Object.printArray(A, n); // Printing the array After sorting

    cout << " " << endl
         << endl;
    cout << "Bubble sort is not Adaptive means for Sorted Array also it will take O(n^2) Time complexity." << endl;
    cout << "Creating bubbleSort_Adaptive() function for Sorted Array and it will take O(n) Time complexity " << endl;

    int A2[] = {2, 4, 7, 9, 11, 17};
    // isSorted =1  Sorted Array take this
    cout << endl
         << "********Sorted Array********" << endl;
    Object.printArray(A2, n);          // Printing the array before sorting
    Object.bubbleSort_Adaptive(A2, n); // Function to sort the array
    cout << endl
         << "********Sorted Array********" << endl;
    Object.printArray(A2, n); // Printing the array After sorting

    return 0;
}

// Bubble Sort:::: Time Complexity is O(n^2)

// Unsorted Array
// index---> 0  1   2  3  4   5
// value---> 7  11  9  2  17  4

//  **********************Bubble Sort***********************
// 1st pass
// Compare and swap index 0 and 1
// index---> 0  1   2  3  4   5
// value---> 7  11  9  2  17  4
//
// Compare and swap index 1 and 2
// index---> 0  1   2   3  4   5
// value---> 7  9   11  2  17  4
//
// Compare and swap index 2 and 3
// index---> 0  1   2   3  4   5
// value---> 7  9   2   11  17  4
//
// Compare and swap index 3 and 4
// index---> 0  1   2   3   4   5
// value---> 7  9   2   11  17  4
//
// Compare and swap index 4 and 5
// index---> 0  1   2   3   4   5*
// value---> 7  9   2   11  4   17     ===> 1st pass is completed
//                              ^
//                              |
//                             Greatest is last Now

// 2nd pass
// Compare and swap index 0 and 1
// index---> 0  1   2   3   4   5*
// value---> 7  9   2   11  4   17
//
// Compare and swap index 1 and 2
// index---> 0  1   2   3   4   5*
// value---> 7  2   9   11  4   17
//
// Compare and swap index 2 and 3
// index---> 0  1   2   3   4   5*
// value---> 7  2   9   11  4   17
//
// Compare and swap index 3 and 4
// index---> 0  1   2   3   4*  5*
// value---> 7  2   9   4   11  17     ===> 2nd pass is completed
//                           ^
//                           |
//                          2nd Greatest is 2nd last Now

// 3rd pass
// Compare and swap index 0 and 1
// index---> 0  1   2   3   4*  5*
// value---> 2  7   9   4   11  17
//
// Compare and swap index 1 and 2
// index---> 0  1   2   3   4*  5*
// value---> 2  7   9   4   11   17
//
// Compare and swap index 2 and 3
// index---> 0  1   2   3* 4*  5*
// value---> 2  7   4   9  11  17      ===> 3rd pass is completed
//                      ^
//                      |
//                     3rd Greatest is 3rd last Now

// 4th pass
// Compare and swap index 0 and 1
// index---> 0  1   2   3* 4*  5*
// value---> 2  7   4   9  11  17
//
// Compare and swap index 1 and 2
// index---> 0  1   2*  3*   4*  5*
// value---> 2  4   7   9    11  17      ===> 4th pass is completed
//                  ^
//                  |
//                 4th Greatest is 4th last Now

// 5th pass
// Compare and swap index 0 and 1
// index---> 0  1*  2*  3*   4*  5*
// value---> 2  4   7   9    11  17    ===> 5th pass is completed
//           ^  ^
//           |  |
//           |  5th Greatest is 5th last Now
//           |
// Smallest element of Array

// Unsorted Array
// index---> 0* 1*  2*  3*   4*  5*
// value---> 2  4   7   9    11  17
