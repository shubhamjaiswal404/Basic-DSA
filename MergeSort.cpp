#include <iostream>
using namespace std;
class MergeSort
{
public:
    void printArray(int *A, int n);
    void merge(int A[], int low, int mid, int high);
    void mergeSort(int A[], int low, int high);
};

void MergeSort::printArray(int *A, int n)
{
    for (int k = 0; k < n; k++)
    {
        cout << "   " << A[k];
    }
    cout << endl;
}

void MergeSort::merge(int A[], int low, int mid, int high)
{
    // int i,j,k,B[high-low+1];
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort::mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    MergeSort Object;
    // int A[]={3,5,2,13,12,3,2,13,45};
    int A[] = {7, 8, 11, 1, 20};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "********Unsorted Array********" << endl;
    Object.printArray(A, n);
    Object.mergeSort(A, 0, n - 1);
    cout << "********Sorted Array********" << endl;
    Object.printArray(A, n);
    cout << "Merge sort is not Adaptive means for Sorted Array also it will take O(nlogn) Time complexity and Stable" << endl;
    cout << "Merge sort Time complexity for Best case , Average case and Worst case all are same O(nlogn) " << endl;
    return 0;
}

// Merge Sort :::: Time Complexity O(nlogn)

// Unsorted Array
// index---> 0  1   2    3   4
// value---> 7  8   11   1   20

// In Merge Sort we divide the array in subarray then using the Merging Procedure
// Example ::
// Slipt the array in Subarray-1 (Note:: using Recursive function to slipt the array, Using low mid and high )
//                                              index---> 0  1   2  |  3   4
//                                              value---> 7  8   11 |  1   20
//                                                                  |
//                                                      |---------------------------------|
//                                                      |                                 |
// Slipt the Subarray-1  in Subarray-2                  |                                 |
//                                            index---> 0  1 |  2  |             index---> 0 |  1
//                                            value---> 7  8 |  11 |             value---> 1 |  20
//                                                           |                               |
//                                      |---------------------------|             |-----------------------------|
//                                      |                           |             |                             |
// Slipt the Subarray-2 in Subarray-3   |                           |             |                             |
//                                index---> 0 | 1          |index---> 0  |    index---> 0 |              index---> 0
//                                value---> 7 | 8          |value---> 11 |    value---> 1 |              value---> 20
//                                            |                 |                  |                              |
//                                      |-------------------|   |                  |-----------------------|      |
//                                      |                   |   |--------------|                           |      |-------------|
// Slipt the Subarray-3 in Subarray-4   |                   |                  |                           |                    |
//                                index---> 0 |       index---> 0          |index---> 0  |             index---> 0 |        index---> 0
//                                value---> 7 |       value---> 8          |value---> 11 |             value---> 1 |        value---> 20
//

// Learn Merging Procedure , are Using Merging Procedure to merge the splited array

// Merging Procedure:::::

// Size = m = 5                                      Size = n = 3

// Sorted Array-1                                    Sorted Array-2
// index---> 0  1   2   3   4                        index---> 0  1   2   3
// value---> 7  9   18  19  22                       value---> 1  6   9   11
//           ^                                                 ^
//           |                                                 |
//           i                                                 j

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5  6  7  8
// value---> 1                                  // Comparing i and j value and inserting j value in array
//           ^                                  // Comparing 7 and 1 , inserting 1 in array
//           |                                  // increment the position of j
//           k

// Sorted Array-1                                    Sorted Array-2
// index---> 0  1   2   3   4                        index---> 0  1   2   3
// value---> 7  9   18  19  22                       value---> 1  6   9   11
//           ^                                                    ^
//           |                                                    |
//           i                                                    j

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5  6  7  8
// value---> 1  6                               // Comparing i and j value and inserting j value in array
//              ^                               // Comparing 7 and 6 , inserting 6 in array
//              |                               // increment the position of j
//              k

// Sorted Array-1                                    Sorted Array-2
// index---> 0  1   2   3   4                        index---> 0  1   2   3
// value---> 7  9   18  19  22                       value---> 1  6   9   11
//           ^                                                        ^
//           |                                                        |
//           i                                                        j

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5  6  7  8
// value---> 1  6   7                            // Comparing i and j value and inserting i value in array
//                  ^                            // Comparing 7 and 9 , inserting 7 in array
//                  |                            // increment the position of i
//                  k

//
// Sorted Array-1                                    Sorted Array-2
// index---> 0  1   2   3   4                        index---> 0  1   2   3
// value---> 7  9   18  19  22                       value---> 1  6   9   11
//              ^                                                     ^
//              |                                                     |
//              i                                                     j

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5  6  7  8
// value---> 1  6   7   9                           // Comparing i and j value and inserting i value in array
//                      ^                            // Comparing 9 and 9 , inserting 9 in array
//                      |                            // increment the position of i
//                      k

//
// Sorted Array-1                                    Sorted Array-2
// index---> 0  1   2   3   4                        index---> 0  1   2   3
// value---> 7  9   18  19  22                       value---> 1  6   9   11
//                   ^                                                ^
//                   |                                                |
//                   i                                                j

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5  6  7  8
// value---> 1  6   7   9   9                       // Comparing i and j value and inserting j value in array
//                          ^                       // Comparing 18 and 9 , inserting 9 in array
//                          |                       // increment the position of j
//                          k

//
// Sorted Array-1                                    Sorted Array-2
// index---> 0  1   2   3   4                        index---> 0  1   2   3
// value---> 7  9   18  19  22                       value---> 1  6   9   11
//                   ^                                                     ^
//                   |                                                     |
//                   i                                                     j

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5  6  7  8
// value---> 1  6   7   9   9  11                     // Comparing i and j value and inserting j value in array
//                             ^                       // Comparming 18 and 11 , inserting 11 in array
//                             |                       // increment the position of j
//                             k

//
// Sorted Array-1                                    Sorted Array-2
// index---> 0  1   2   3   4                        index---> 0  1   2   3
// value---> 7  9   18  19  22                       value---> 1  6   9   11
//                   ^                                                         ^
//                   |                                                         |
//                   i                                                         j

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5   6  7  8
// value---> 1  6   7   9   9  11  18                    // Now Comparison is not possible because Sorted Array-2 is over
//                                ^                       // Now insert all the element of Sorted Array-1 in array
//                                |
//                                k

// Sorted Array-1                                    Sorted Array-2
// index---> 0  1   2   3   4                        index---> 0  1   2   3
// value---> 7  9   18  19  22                       value---> 1  6   9   11
//                   ^                                                         ^
//                   |                                                         |
//                   i                                                         j

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5   6   7   8
// value---> 1  6   7   9   9  11  18  19                   // Now Comparison is not possible because Sorted Array-2 is over
//                                      ^                       // Now insert all the element of Sorted Array-1 in array
//                                      |
//                                      k

// Size = m + n = 5 + 3 = 8
// index---> 0  1   2   3   4  5   6   7   8
// value---> 1  6   7   9   9  11  18  19  22                 // Now Comparison is not possible because Sorted Array-2 is over
//                                          ^                       // Now insert all the element of Sorted Array-1 in array
//                                          |
//                                          k

// Now using Merging procedure we get big sorted array from small two sorted array
//
// Now After the Slipting the subarray til single element Merging Procedure start , single element can considered as sorted array
// Two Sigle element are Merge by Merge procedure and give sorted array of two element and so on

// Now Moving A Head
//                                      Sorted-Array        Sorted-Array          Sorted-Array              Sorted-Array         Sorted-Array
//                                      index---> 0 |       index---> 0          |index---> 0  |             index---> 0 |        index---> 0
//                                      value---> 7 |       value---> 8          |value---> 11 |             value---> 1 |        value---> 20
//                                           |                   |                   |                           |                    |
//                                           |                   |            |------|                           |             |------|
//                                           |-------------------|            |                        |---------|             |
//                                                 |                          |                        |                       |
// Merging the Subarray-3 in Subarray-4            |                          |                        |                       |
//                                             Sorted-Array              Sorted-Array              Sorted-Array         Sorted-Array
//                                             index---> 0   1          |index---> 0  |             index---> 0 |        index---> 0
//                                             value---> 7   8          |value---> 11 |             value---> 1 |        value---> 20
//                                                    |                           |                   |                         |
//                                                    |---------------------------|                   |-------------------------|
//                                                                    |                                               |
// Merging the Subarray-2 in Subarray-3                               |                                               |
//                                                                Sorted-Array                                  Sorted-Array
//                                                                index---> 0   1  2                            index---> 0  1
//                                                                value---> 7   8  11                           value---> 1  20
//                                                                          |                                         |
//                                                                          |-----------------------------------------|
//                                                                                                |
// Merging the Subarray-2 in Subarray-1                                                           |
//                                                                                          Sorted-Array
//                                                                                          index---> 0   1  2   3   4
//                                                                                          value---> 1   7  8   11  20
//

// Sorted Array
// index---> 0  1   2   3    4
// value---> 1  7   8   11   20
