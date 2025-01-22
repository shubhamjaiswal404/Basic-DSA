#include <iostream>
using namespace std;
template <class T>

class myClass
{
public:
    T data;
    void display();
    myClass(T a)
    {
        data = a;
    }

    // writing function display inside class
    //  void display(){
    //      cout<<data;
    //  }
};

// writing function display outside class
//  Member Function Template
template <class T>
void myClass<T>::display()
{
    cout << data;
}

//  Normal Function
void func(int a)
{
    cout << "I am Normal Function  func() ----->    " << a << endl;
}

// Template function
template <class T>
void func(T a)
{
    cout << "I am Template Function func() ----->   " << a << endl;
}

template <class T>
void func1(T a)
{
    cout << "I am Template func() ----->   " << a << endl;
}

int main()
{
    cout << "*******************Member Function Template*******************" << endl;
    myClass<int> Object(5);
    cout << endl
         << "int ---> " << Object.data << endl;
    cout << "Display, the data store by Object in myClass class of int datatype " << endl
         << "data = ";
    Object.display(); // Member Function Template

    myClass<float> Object2(5.7);
    cout << endl
         << endl
         << "float --->  " << Object2.data << endl;
    cout << "Display, the data store by Object in myClass class of float datatype " << endl
         << "data = ";
    Object2.display(); // Member Function Template

    myClass<char> Object3('A');
    cout << endl
         << endl
         << "char --->  " << Object3.data << endl;
    cout << "Display, the data store by Object in myClass class of char datatype " << endl
         << "data = ";
    Object3.display(); // Member Function  Template

    cout << endl
         << "NOTE:::  Easily switching the datatype of data using Template " << endl;

    cout << endl
         << "*******************Overloading Function Template*******************" << endl;
    cout << "Two function of same name func" << endl;
    cout << "func() ----->Normal Function " << endl;
    cout << "func() ----->Template Function " << endl
         << endl;

    func(4); // Exact match takes the heighest priority
    func(4.1);
    func('A');

    cout << endl
         << "NOTE :: for int it give priority to Nomal function because it is a exact match and {Exact match :: ---->  Normal function > Template function } " << endl;
    cout << endl
         << "That's why I have to create function with function name func1() " << endl;
    func1(4);

    return 0;
}