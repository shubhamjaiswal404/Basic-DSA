#include<iostream>
using namespace std;

class QuickSort{
    public:
    void printArray(int *A, int n);
    int partition(int A[],int low,int high);
    void quickSort(int A[],int low, int high);
};


void QuickSort::printArray(int *A, int n)
{
    for (int k = 0; k < n; k++)
    {
        cout << "   " << A[k];
    }
    cout << endl;
}

int QuickSort::partition(int A[],int low,int high){
    
    int pivot=A[low];
    int i = low +1;
    int j = high;
    int temp;

    do
    {
    while(A[i]<=pivot){
        i++;
    }
    while(A[j]>pivot){
        j--;
    }

    if(i<j){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }


    } while (i<=j);
    

    // Swap A[low] and A[j]
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
     
    return j;
}

void QuickSort::quickSort(int A[],int low, int high){
    
    int partitionIndex;// Index of pivot after partition
    if(low<high){
    partitionIndex=partition(A,low,high);
    quickSort(A,low,partitionIndex-1);//sort left subarray
    quickSort(A,partitionIndex+1,high);//sort right subarray
    }

}

int main(){
    QuickSort Object;
    int A[]={2,4,3,9,1,4,8,7,5,6};
    int n =sizeof(A)/sizeof(A[0]);

    cout << "********Unsorted Array********" << endl;
    Object.printArray(A,n);
    Object.quickSort(A,0,n-1);
    cout << "********Sorted Array********" << endl;
    Object.printArray(A,n);
    cout << "Quick sort is not Adaptive means for Sorted Array also it will take O(n^2) Time complexity and Not Stable" << endl;
    cout<<"Average Case Time complexity is O(nlogn) and Waste case Time Complexity is O(n^2) "<<endl;
   
    return 0;
}
// Quick Sort:::: Time Complexity is O(n^2)
// Average Case Time complexity is O(nlogn) 

// Partitioning 
//1) i = low
//2) j = high 
//3) pivot= low
//4) i++ until element > pivot is found
//5) j-- until element <= pivot is found
//6) swap A[i] & A[j] and repeat 4 & 5 until j<=i
//7) swap pivot & A[j]


// 2    4    3   9   1   4   8   7    5     6           { Move i to get greater then 2 or equal}
// ^    ^                                   ^           { Move j to get lesser  then 2 or equal}
// |    |                                   |           { j cross i then change swap pivot by j}
// p    i                                   j           { partially sort---> Partition }

// 2    4    3   9   1   4   8   7    5     6
// ^    ^                             ^
// |    |                             |
// p    i                             j 

// 2    4    3   9   1   4   8   7    5     6
// ^    ^                        ^
// |    |                        |
// p    i                        j 

// 2    4    3   9   1   4   8   7    5     6
// ^    ^                    ^
// |    |                    |
// p    i                    j 

// 2    4    3   9   1   4   8   7    5     6
// ^    ^                ^
// |    |                |
// p    i                j 

// 2    4    3   9   1   4   8   7    5     6
// ^    ^            ^
// |    |            |                                  // Swapping Now
// p    i            j 

// 2    1    3   9   4   4   8   7    5     6
// ^    ^            ^
// |    |            |                                  // Swapping 
// p    i            j 

// 2    1    3   9   4   4   8   7    5     6
// ^         ^   ^
// |         |   |                                  
// p         i   j 

// 2    1    3   9   4   4   8   7    5     6
// ^         ^^                                  // i and j cross each other poivat == j
// |         ||                                  
// p        i,j   

// 2    1    3   9   4   4   8   7    5     6
// ^    ^   ^                                  // i and j cross each other poivat == j
// |    |   |                                  
// p    j   i

// 1    2    3   9   4   4   8   7    5     6
// ^    ^   ^                                  // i and j cross each other poivat == j
// |    |   |                                  
// p    j   i

// Now spliting the Array in 2 subarray

// 1<------------------------2------------------------> 3   9   4   4   8   7    5     6
// ^                         ^                   ^                                  // i and j cross each other poivat == j
// |                         |                   |                                  
// p                         j                   i

// Reapeating the same till array get sort
// 3   9   4   4   8   7    5     6 
// ^   ^                          ^                                  
// |   |                          |                                  
// p   i                          j

// 3   9   4   4   8   7    5     6 
// ^   ^                    ^                                  
// |   |                    |                                  
// p   i                    j

// 3   9   4   4   8   7    5     6 
// ^   ^               ^                                  
// |   |               |                                  
// p   i               j

// 3   9   4   4   8   7    5     6 
// ^   ^           ^                                  
// |   |           |                                  
// p   i           j

// 3   9   4   4   8   7    5     6 
// ^   ^       ^                                  
// |   |       |                                  
// p   i       j

// 3   9   4   4   8   7    5     6 
// ^   ^   ^                                  
// |   |   |                                  
// p   i   j

// 3   9   4   4   8   7    5     6 
// ^   ^^                                  
// |   ||                                  
// p   i,j

// 3    9   4   4   8   7    5     6 
// ^^   ^                                  
// ||   |                                  
// p,j  i

// Now spliting the Array in 2 subarray
//<---------3------------------------> 9   4   4   8   7    5     6 
//          ^^                   ^                                  
//          ||                   |                                  
//         p,j                   i


// 9   4   4   8   7    5     6 
// ^   ^                      ^                                  
// |   |                      |                                  
// p   i                      j

// 9   4   4   8   7    5     6 
// ^       ^                  ^                                  
// |       |                  |                                  
// p       i                  j

// 9   4   4   8   7    5     6 
// ^           ^              ^                                  
// |           |              |                                  
// p           i              j

// 9   4   4   8   7    5     6 
// ^               ^          ^                                  
// |               |          |                                  
// p               i          j

// 9   4   4   8   7    5     6 
// ^                    ^     ^                                  
// |                    |     |                                  
// p                    i     j

// 9   4   4   8   7    5     6 
// ^                          ^^                                  
// |                          ||                                  
// p                          i,j


// 9   4   4   8   7    5     6 
// ^                          ^   ^                                  
// |                          |   |             // i and j cross each other poivat == j                     
// p                          j   i

// 6   4   4   8   7    5     9 
// ^                          ^   ^                                  
// |                          |   |             // i and j cross each other poivat == j                     
// p                          j   i

// Now spliting the Array in 2 subarray
// 6   4   4   8   7    5 <--------------------------9------------------------>
// ^                                                 ^                           ^                                  
// |                                                 |                           |             // i and j cross each other poivat == j                     
// p                                                 j                           i

// 6   4   4   8   7    5
// ^   ^                ^                                  
// |   |                |                                  
// p   i                j

// 6   4   4   8   7    5
// ^       ^            ^                                  
// |       |            |                                  
// p       i            j

// 6   4   4   8   7    5
// ^           ^        ^                                  
// |           |        |   // swapping Now                               
// p           i        j

// 6   4   4   5   7    8
// ^           ^        ^                                  
// |           |        |   // swapping Now                               
// p           i        j

// 6   4   4   5   7    8
// ^               ^^                                  
// |               ||                                  
// p               i,j

// 6   4   4   5   7    8
// ^           ^   ^                                  
// |           |   |                     // i and j cross each other poivat == j             
// p           j   i

// Now spliting the Array in 2 subarray
// 5   4   4<------------------6------------------------> 7    8
// ^                           ^                      ^                                  
// |                           |                      |                     // i and j cross each other poivat == j             
// p                           j                      i

// 5   4   4  
// ^   ^   ^                                  
// |   |   |                                  
// p   i   j

// 5   4   4  
// ^       ^^                                  
// |       ||                                  
// p       i,j

// 5   4   4  
// ^       ^    ^                                  
// |       |    |                  // i and j cross each other poivat == j                 
// p       j    i

// Now spliting the Array in 2 subarray
// 4   4 <---------------5------------------------>                  
// ^                     ^           ^                                  
// |                     |           |                  // i and j cross each other poivat == j                 
// p                     j           i

// 7   8     
// ^   ^^                                  
// |   ||                                  
// p   i,j

// 7     8     
// ^^    ^                                  
// ||    |                                  // i and j cross each other poivat == j 
// p,j   i
// Now spliting the Array in 2 subarray
//<---------7------------------->8     
// ^        ^                    ^                                  
// |        |                    |                                   
// p        j                    i
