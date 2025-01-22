#include <iostream>
using namespace std;

class InsertionSort
{
public:
    void printArray(int *A, int n);
    void insertionSort(int *A, int n);
};

void InsertionSort::printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << A[i];
    }
    cout << endl;
}

void InsertionSort::insertionSort(int *A, int n)
{
    int Key, j;
    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        // Loop for each pass
        cout << "Working on pass number " << i << " , Number of Comparisons possible is  " << i << " and Swaps possible is  " << i << endl;
        Key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > Key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = Key;
    }
}

int main()
{
    InsertionSort Object;
    int A[] = {7, 2, 91, 77, 3};
    int n = 5;
    cout << "********Unsorted Array********" << endl;
    Object.printArray(A, n);
    Object.insertionSort(A, n);
    cout << endl
         << "********Sorted Array********" << endl;
    Object.printArray(A, n);
    cout << "Insertion sort in Adaptive mean for sorted array it will take O(n) Time complexity and for Unsorted array it will take O(n^2) Time complexity" << endl;
    return 0;
}

// Insertion sort :::: Time Complexity is O(n^2)

// Unsorted Array
// index---> 0  1   2   3   4
// value---> 7  2   91  77  3

//         Sort |  Not-Sort
// index---> 0  |  1   2   3   4
// value---> 7  |  2   91  77  3           ----------------->Key =2,j=0,i=1

//         Sort |  Not-Sort
// index---> 0  |  1   2   3   4
// value---> 7  | ---  91  77  3            // Comparing 2 with 7
//                                   2*    ----------------->Key =2,j=0,i=1
//
//         Sort |  Not-Sort
// index---> 0  |  1   2   3   4
// value---> ---|  7   91  77  3           // Increment position of 7
//                                   2*    ---------------->Key =2,j=-1,i=1
//         Sort |  Not-Sort
// index---> 0  |  1   2   3   4          // Inserting the Key in array and 1st pass is done
// value---> 2  |  7   91  77  3

//           Sort   |  Not-Sort
// index---> 0   1  |  2   3   4            ----------------->Key = 91,j=1,i=2
// value---> 2   7  |  91  77  3

//           Sort   |  Not-Sort
// index---> 0   1  |  2   3   4          // Comparing 91 with 7
// value---> 2   7  | ---  77  3          ----------------->Key = 91,j=1,i=2
//                                   91*

//           Sort      |  Not-Sort
// index---> 0   1  2  |  3   4          // Inserting the Key in array and 2nd pass is done
// value---> 2   7  91 |  77  3

//           Sort      |  Not-Sort
// index---> 0   1  2  |  3   4            ----------------->Key = 77,j=2,i=3
// value---> 2   7  91 |  77  3

//           Sort      |  Not-Sort
// index---> 0   1  2  |  3   4             // Comparing 77 with 91
// value---> 2   7  91 | ---  3             ----------------->Key = 77,j=2,i=3
//                                  77*
//
//           Sort           | Not-Sort
// index---> 0   1  2    3  |  4           //  Increment position of 91
// value---> 2   7 ---   91 |  3           ----------------->Key = 77,j=1,i=3
//                                 77*
//
//
//           Sort           | Not-Sort
// index---> 0   1  2    3  |  4           // Comparing 77 with 7
// value---> 2   7 ---   91 |  3           ----------------->Key = 77,j=1,i=3
//                                 77*

//           Sort           | Not-Sort
// index---> 0   1  2    3  |  4          // Inserting the Key in array and 3rd pass is done
// value---> 2   7  77   91 |  3
//

//           Sort           | Not-Sort
// index---> 0   1  2    3  |  4           ----------------->Key = 3,j=3,i=4
// value---> 2   7  77   91 |  3
//
//
//           Sort           | Not-Sort
// index---> 0   1  2    3  |  4          // Comparing  3 with 91
// value---> 2   7  77   91 | ---         ----------------->Key = 3,j=3,i=4
//                                  3*
//
//           Sort                 |  Not-Sort
// index---> 0   1  2    3    4   |             //  Increment position of 91
// value---> 2   7  77  ---   91  |              ----------------->Key = 3,j=3,i=4
//                                    3*

//
//
//           Sort                 |  Not-Sort
// index---> 0   1  2    3    4   |              //  Comparing  3 with 77
// value---> 2   7  77  ---   91  |              ----------------->Key = 3,j=2,i=4
//                                    3*

//
//           Sort                |  Not-Sort
// index---> 0   1  2   3    4   |              //  Increment position of 77
// value---> 2   7 ---  77   91  |              ----------------->Key = 3,j=2,i=4
//                              3*
//
//
//           Sort                |  Not-Sort
// index---> 0   1  2   3    4   |              //  Comparing  3 with 77
// value---> 2   7 ---  77   91  |              ----------------->Key = 3,j=1,i=4
//                              3*
//
//           Sort                |  Not-Sort
// index---> 0   1  2   3    4   |              //  Increment position of 7
// value---> 2  --- 7   77   91  |              ----------------->Key = 3,j=1,i=4
//                              3

//
//           Sort                |  Not-Sort
// index---> 0   1  2   3    4   |          // Inserting the Key in array and 4th pass is done
// value---> 2   3  7   77   91  |

// Sorted Array
// index---> 0  1   2   3   4
// value---> 2  3   7   77  91
