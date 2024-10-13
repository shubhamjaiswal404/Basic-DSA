#include<iostream>
using namespace std;


int linearSearch(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    
    return -1;
}

int binarySearch(int arr[],int size,int element){
    int low,mid,high;
    low=0;
    high=size-1;
// starts searching
// keep searching until low<= high converges
    while(low<=high){

    mid=(low+high)/2;

    if(arr[mid]==element){
        return mid;
    }

    if(arr[mid]<element){
        low=mid+1;
    }
    else{
        high=mid-1;
    }

    }
// searching ends
        return -1;
}

int main(){
    cout<<"************Linear Search************"<<endl;
    // Unsorted array for linear search
    int unsorted_array[]={4,8,10,12,15,11,2,8};
    int element_linear = 11;
    int size_linear = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    int Linear_searchIndex =linearSearch(unsorted_array,size_linear,element_linear);
    cout<<"The element "<<element_linear<<" was found at index "<<Linear_searchIndex<<endl;


    cout<<"************Binary Search************"<<endl;
    // sorted array for binary search
    int sorted_array[]={2,8,14,32,66,100,104,200,400};
    int element_binary = 200;
    int size_binary = sizeof(sorted_array)/sizeof(sorted_array[0]);
    int Binary_searchIndex =binarySearch(sorted_array,size_binary,element_binary);
    cout<<"The element "<<element_binary<<" was found at index "<<Binary_searchIndex<<endl;
    return 0;
}

// Linear search (Note:: unsorted array)
// searching for 11

//index-->    0  1   2   3   4   5  6  7  
//Elements--> 4 ,8 ,10 ,12 ,15 ,11 ,2 ,8 
//            ^
//            |
// check 11 = 4 Not found

//index-->    0  1   2   3   4   5  6  7  
//Elements--> 4 ,8 ,10 ,12 ,15 ,11 ,2 ,8 
//               ^
//               |
// check 11 = 8 Not found

//index-->    0  1   2   3   4   5  6  7  
//Elements--> 4 ,8 ,10 ,12 ,15 ,11 ,2 ,8 
//                   ^
//                   |
// check 11 = 10 Not found

//index-->    0  1   2   3   4   5  6  7  
//Elements--> 4 ,8 ,10 ,12 ,15 ,11 ,2 ,8 
//                       ^
//                       |
// check 11 = 12 Not found

//index-->    0  1   2   3   4   5  6  7  
//Elements--> 4 ,8 ,10 ,12 ,15 ,11 ,2 ,8 
//                           ^
//                           |
// check 11 = 15 Not found

//index-->    0  1   2   3   4   5  6  7  
//Elements--> 4 ,8 ,10 ,12 ,15 ,11 ,2 ,8 
//                               ^
//                               |
// check 11 = 11 Found return index 5


// Binary Search (Note::Sorted array )
// searching for 200

//index-->    0  1   2   3   4   5    6    7   8
//Elements--> 2 ,8 ,14 ,32 ,66 ,100 ,104 ,200,400
//            ^              ^                 ^
//            |              |                 |
//           low            mid               high
// check 200 = 66 Not found

//index-->    0  1   2   3   4   5    6    7   8
//Elements--> 2 ,8 ,14 ,32 ,66 ,100 ,104 ,200,400
//                           ^         ^        ^
//                           |         |        |
//                          low       mid     high
// check 200 = 104 Not found

//index-->    0  1   2   3   4   5    6    7   8
//Elements--> 2 ,8 ,14 ,32 ,66 ,100 ,104 ,200,400
//                                     ^   ^   ^
//                                     |   |   |
//                                    low  mid high
// check 200 = 200 Found return index 7

// low     high     mid     Element 
// 0        8        4      Not found
// 4        8        6      Not found 
// 6        8        7       Found







