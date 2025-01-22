//************************************** Without Using Template **************************************
// #include <iostream>
// using namespace std;

// class vector
// {
// public:
//     int *arr;
//     int size;
//     // Constructor of class vector
//     vector(int m)
//     {
//         size = m;
//         arr = new int[size]; // Dynamically allocating memory
//     }

//     int dotProduct(vector &v)
//     {
//         int d = 0;
//         for (int i = 0; i < size; i++)
//         {
//             d += this->arr[i] * v.arr[i]; // d = v1.arr[0]*v2.arr[0] + v1.arr[1]*v2.arr[1] + v1.arr[2]*v2.arr[2]
//         }
//         return d;
//     }
// };

// int main()
// {
//     vector v1(3);
//     v1.arr[0] = 4;
//     v1.arr[1] = 3;
//     v1.arr[2] = 1;

//     vector v2(3);
//     v2.arr[0] = 1;
//     v2.arr[1] = 0;
//     v2.arr[2] = 1;
//     //  Calculating value of Dot product of vector v1 and v2
//     int a = v1.dotProduct(v2);
//     // Printing the final answer
//     cout << "******DotProduct**************" << endl
//          << "=> a = 4*1 + 3*0 + 1*1 = 5  " << endl;
//     cout << "a = " << a << endl;

//     return 0;
// }


//**************************************  Using Template **************************************
// #include <iostream>
// using namespace std;

// template<class T>

// class vector
// {
// public:
//     T *arr;
//     int size;
//     // Constructor of class vector
//     vector(int m)
//     {
//         size = m;
//         arr = new T [size]; // Dynamically allocating memory
//     }

//     T dotProduct(vector &v)
//     {
//         T d = 0;
//         for (int i = 0; i < size; i++)
//         {
//             d += this->arr[i] * v.arr[i]; // d = v1.arr[0]*v2.arr[0] + v1.arr[1]*v2.arr[1] + v1.arr[2]*v2.arr[2]
//         }
//         return d;
//     }
// };

// int main()
// {
//     cout<<"*********Template*************"<<endl<<endl;
//     cout<<"class ----> Object         Object ke liye class Template hai  "<<endl;
//     cout<<"Template ----> class       class ke liye Template Template hai   "<<endl;
//     vector<float> v1(3);
//     v1.arr[0] = 4;
//     v1.arr[1] = 3.3;
//     v1.arr[2] = 1;

//     vector<float> v2(3);
//     v2.arr[0] = 1.2;
//     v2.arr[1] = 0;
//     v2.arr[2] = 1.9;
//     //  Calculating value of Dot product of vector v1 and v2
//     float a = v1.dotProduct(v2);
//     // Printing the final answer
//     cout << "******DotProduct**************" << endl
//          << "=> a = 4*1.2 + 3.3*0 + 1*1.9 = 6.7  " << endl;
//     cout << "a = " << a << endl;

//     return 0;
// }
// NOTE:: 
// I want to do Dotproduct 
//  
//  class vector{
//      int * arr ;  -----> int 
//      int size;
//      public:
//          }-------------------------> vectorInt,vectorFloat,vectorDouble,vectorChar for different datatype different class are created

//It will give correct answer for int datatype  and wrong answer for other datatype

//That's why I have to create multiple classes for other datatypes, like for float, char , double , long 

//I have to craete multiple class for int , for char , for float , for double      ===> Solution is Template 

//After using Template , one time class is define general for any datatype int , float , char , double 

// Synatax for Template
// 
// template <class T>
// class vector{
//      T*arr;   -----> T can be int ,float ,char
//    public:
//      vector(T*arr)
//      {
//          // code
//        }    
//      }
// 
// different class are used coming from same Templates
//  
//      vector <int> v1() ----> class for int 
//      vector <float> v2() ----> class for float
//      vector <double> v2()  ----> class for double
//      vector <char> v2()  ----> class for char


    