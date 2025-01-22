#include<iostream>
using namespace std;

class SelectionSort{
    public:
    void printArray(int *A, int n);
    void selectionSort(int *A,int n);

};

void SelectionSort::printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << A[i];
    }
    cout << endl;
}

void SelectionSort::selectionSort(int *A,int n){
 cout<<"Running Selection Sort ....\n"<<endl;
 for (int i = 0; i < n-1; i++) //For Number of pass
 {
 cout << "Working on pass number " << i+1 << " , Number of Comparisons possible is  " << n-i-1 << " and Swaps possible is 1 " << endl;
 int indexOfMin,temp;
    indexOfMin=i;
   for (int j = i+1; j < n; j++)
   {
    //finding the minimum element
    if (A[j]<A[indexOfMin])
    {
        indexOfMin=j;
    }
   }
   temp=A[i];
   A[i]=A[indexOfMin];
   A[indexOfMin]=temp;
 }
 
}

int main(){
    SelectionSort Object;
    int A[]={8,0,7,1,3};
    int n= 5;
    cout << "********Unsorted Array********" << endl;
    Object.printArray(A,n);
    Object.selectionSort(A,n);
    cout << "********Sorted Array********" << endl;
    Object.printArray(A,n);
    cout << "Selection sort is not Adaptive means for Sorted Array also it will take O(n^2) Time complexity and not Stable" << endl;


    return 0;
}


// Selection Sort :::: Time Complexity is O(n^2)

// Unsorted Array
// index---> 0  1   2   3   4
// value---> 8  0   7   1   3

//     Sort  |  Not-Sort
// index---> | 0    1   2   3   4
// value---> | 8*   0   7   1   3           // Assume 8 as minimum as starting index
//             ^
//             |
//         minimum   

//     Sort  |  Not-Sort
// index---> | 0    1   2   3   4
// value---> | 8*   0   7   1   3         // Comparing 8 with 0 and 0 is minimum
//                  ^
//                  |
//               minimum

//     Sort  |  Not-Sort
// index---> | 0    1   2   3   4
// value---> | 8*   0   7   1   3       // Comparing 0 with 7 and 0 is minimum
//                  ^
//                  |
//               minimum

//     Sort  |  Not-Sort
// index---> | 0    1   2   3   4
// value---> | 8*   0   7   1   3       // Comparing 0 with 1 and 0 is minimum
//                  ^
//                  |
//               minimum

//     Sort  |  Not-Sort
// index---> | 0    1   2   3   4
// value---> | 8*   0   7   1   3       // Comparing 0 with 3 and 0 is minimum
//                  ^
//                  |
//               minimum



//         Sort  |  Not-Sort
// index---> 0   | 1    2   3   4
// value---> 0   | 8*   7   1   3       // Swapping minimum element 0 with 8*
//                 ^
//                 |
//              minimum   

// Pass 1 is completed

//         Sort  |  Not-Sort
// index---> 0   | 1    2   3   4
// value---> 0   | 8*   7   1   3       // Assume 8 as minimum as starting index       
//                 ^
//                 |
//              minimum   

//         Sort  |  Not-Sort
// index---> 0   | 1    2   3   4
// value---> 0   | 8*   7   1   3       // Comparing 8 with 7 and 7 is minimum
//                      ^
//                      |
//                   minimum


//         Sort  |  Not-Sort
// index---> 0   | 1    2   3   4
// value---> 0   | 8*   7   1   3       // Comparing 7 with 1 and 1 is minimum
//                          ^
//                          |
//                      minimum   

//         Sort  |  Not-Sort
// index---> 0   | 1    2   3   4
// value---> 0   | 8*   7   1   3      // Comparing 1 with 3 and 1 is minimum 
//                          ^
//                          |
//                      minimum 

//         Sort      |     Not-Sort
// index---> 0    1  |   2    3   4
// value---> 0    1  |   7*   8   3       // Swapping minimum element 1 with 8*
//                       ^
//                       |
//                     minimum 

// Pass 2 is completed

//         Sort      |     Not-Sort
// index---> 0    1  |   2    3   4
// value---> 0    1  |   7*   8   3       // Assume 7 as minimum as starting index
//                       ^
//                       |
//                     minimum 

//         Sort      |     Not-Sort
// index---> 0    1  |   2    3   4
// value---> 0    1  |   7*   8   3       // Comparing 7 with 8 and 7 is minimum 
//                       ^
//                       |
//                     minimum 

//         Sort      |     Not-Sort
// index---> 0    1  |   2    3   4
// value---> 0    1  |   7*   8   3       // Comparing 7 with 3 and 3 is minimum 
//                                ^
//                                |
//                             minimum 


//         Sort          |  Not-Sort
// index---> 0    1   2  |  3   4
// value---> 0    1   3  |  8*   7       // Swapping minimum element 3 with 7*
//                          ^
//                          |
//                       minimum 

// Pass 3 is completed

//         Sort          |  Not-Sort
// index---> 0    1   2  |  3   4
// value---> 0    1   3  |  8*   7       // Assume 8 as minimum as starting index
//                          ^
//                          |
//                        minimum 

//         Sort          |  Not-Sort
// index---> 0    1   2  |  3   4
// value---> 0    1   3  |  8*   7       // Comparing 8 with 7 and 7 is minimum
//                               ^
//                               |
//                            minimum 

//         Sort              |  Not-Sort
// index---> 0    1   2  3   | 4
// value---> 0    1   3  7   | 8*       // Swapping minimum element 7 with 8*
//                             ^
//                             |
//                           minimum 

// Pass 4 is completed

//         Sort                    |  Not-Sort
// index---> 0    1   2  3   4     |
// value---> 0    1   3  7   8     |      // Last element is Largest element in the Array
//                             


// Sorted Array
// index---> 0  1   2   3   4
// value---> 0  1   3   7   8