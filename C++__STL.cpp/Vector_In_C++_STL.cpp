#include <iostream>
#include <vector> // Header file of vector
using namespace std;

void display(vector<int> &v)
{                                                       // vector <int> ---> int, vector <float> ---> float , vector <char> ---> char
    cout << endl
         << "Display this vector in v[i]::" << endl;     //&v -----> Reference of integer vector
    for (int i = 0; i < v.size(); i++)
    {                                                    // size() ---> reference member function of vector {method:: Return size }
        cout << v[i] << "  ";                           // v[i] ==> arr[i] similiar analogy
    }

    cout << endl;

    cout << "Display this vector in v.at(i)::" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << "  ";                        // v.at(i) ==> arr[i] similiar analogy
    }

    cout << endl;
}

// Function Template
template <class T>
void display(vector<T> &v)
{

    cout << "Display this vector ::" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << "    ";                          // v.at(i) ==> arr[i] similiar analogy
    }
}

int main()
{

    int element, size;

    vector<int> vec1;                                   // zero length integer vector

    cout << "Enter the size of your vector " << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {

        cout << "Enter an Element to add to this vector " << endl;
        cin >> element;

        vec1.push_back(element);                             // member function of vector {method::Add element at the end}
        cout << "Add element at the end" << endl;
    }

    cout << "**************Display function is called **************" << endl;
    display(vec1);                                          // call display() function

    cout << endl
         << "******Delete last element******" << endl;
    vec1.pop_back();                                        // member function of vector {method::Delete last element }
    display(vec1);                                           // call display() function

    vector<int>::iterator iter = vec1.begin();              // iter ---> iterator ==> pointer
//                                                         // iter ---> name
//                                                          // iter ---> now 111 will be on 1st position
//                                                          //vec1.begin()  ---->   iterator will point 1st element
//                                                          //begin() ---> reference member function of vector {method:: Return iterator to beginning }
    vec1.insert(iter, 111);                                 // insert() ---> reference member function of vector {method:: Insert elements  }
    cout << endl
         << "******Inserting 111 will be on 1st position******" << endl;
    display(vec1);                                               // call display() function

    vec1.insert(iter + 1, 222);                                 // iter + 1 ---> now 222 will be on 2nd position
    cout << endl
         << "******Inserting 222 will be on 2nd position******" << endl;
    display(vec1);

    vec1.insert(iter + 1, 5, 333);                               // ---> now  5 copy of 333 will be inserted
    cout << endl
         << "******Inserting 5 copy of 333 , from 2nd position******" << endl;
    display(vec1);

    // Way to create a vector
    cout << endl
         << "********vec3*********" << endl
         << endl;
    cout << "Empty array of char datatype , array of size 4 is created but not visible means vec2 is not initiallized " << endl;
    vector<char> vec2(4);                                        // 4-element character vector
    cout << endl
         << "vec2  4 elements are empty and push_back ,Add element at the end that's why insertion of A is After 4 empty elements" << endl;
    vec2.push_back('A');                                         // member function of vector {method::Add element at the end}
    display(vec2);
    cout << endl
         << "vec2  4 elements are empty and push_back ,Add element at the end that's why insertion of B is After 4 empty elements and A" << endl;
    vec2.push_back('B');                                         // member function of vector {method::Add element at the end}
    display(vec2);
    cout << endl
         << "vec2  4 elements are empty and push_back ,Add element at the end that's why insertion of C is After 4 empty elements and A , B" << endl;
    vec2.push_back('C');                                       // member function of vector {method::Add element at the end}
    display(vec2);
    cout << endl
         << "vec2   4 elements are empty and push_back ,Add element at the end that's why insertion of D is After 4 empty elements and A , B , C" << endl;
    vec2.push_back('D');                                         // member function of vector {method::Add element at the end}
    display(vec2);

    // Use the copy constructor to create a new vector vec3
    vector<char> vec3(vec2);                                    // 4-element character vector from vec2

    cout << endl
         << "********vec3*********" << endl;
    cout << "vec3 will be copy the vec2 , copy is store in vec3" << endl;
    display(vec3);

    cout << endl
         << "********vec4*********" << endl
         << endl;
    cout << endl
         << "6-element vector means of size 6 and all values are 13" << endl;
    vector<int> vec4(6, 13);                                     // 6-element vector of 13
    display(vec4);
    return 0;
}


// Big Array element fill until full copy to the next big array
// synax of vector
// vector <int> vec1;
//          ^
//          |-----type of vector
// vector manage size automatically ------>  array mae size fixed adding extra element is difficult

// Google{ cpp vector methods ---> C++.com -----> reference ----> member function {methods} }