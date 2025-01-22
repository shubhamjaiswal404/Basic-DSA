#include <iostream>
using namespace std;

template<class T1, class T2>    // without function template , that's why comment
                                // many function due to many data type are now easy to slove
float funcAverage(T1 a,T2 b){   // mean we no need to specify the datatype of argument of function it automatically identify
    float avg = (a+b)/2.0;
    return avg;
}

float funcAverage_1(int a, int b)
{
    float avg = (a + b) / 2;
    return avg;
}

float funcAverage_2(int a, int b)
{
    float avg = (a + b) / 2.0; // Because of 2.0 evalution take in float
    return avg;
}

float funcAverage_3(int a, float b)
{
    float avg = (a + b) / 2.0;
    return avg;
}

template <class T> // function Template
void swapp(T &a, T &b)
{ // swap there is stdanard name space in C++ use swapp
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    float a;
    cout << "**************************Function Template **************************" << endl;

    
    cout<<"*************Before using Function template ::*************"<<endl<<endl;


    a = funcAverage_1(5, 2);


    cout << "Error::Average is 0, Because argument of function are in int , that's why evalulate in int and return in float" << endl;

    printf("The average of these number is %d \n\n", a); // format specifier is of integer %d

    cout << "Error::Average is 3, Because argument of function are in int , that's why evalulate in int and return in float" << endl
         << endl;

    printf("The average of these number is %f \n", a); // format specifier is of float %f
    printf("The average of these number is %.3f \n\n", a);


    a = funcAverage_2(5, 2);


    cout << "Average is 3.5 correct , Because argument of function are in int , that's why evalulate in float and return in float" << endl
         << endl;

    printf("The average of these number is %f \n", a); // format specifier is of float %.3f
    printf("The average of these number is %.3f \n", a);
    cout << a << endl<<endl;


    a = funcAverage_2(5, 2.4);


    cout << "Error:: Average is 3.5  , Because argument of function are in int , and I passed float  that's why evalulate in float and return in float but argument are take as integer" << endl
         << endl;

    printf("The average of these number is %f \n", a);
    printf("The average of these number is %.3f \n", a);

    cout << a << endl<<endl;

    cout << "Average is 3.7 correct , Because argument of function are in float , and I passed float that's why evalulate in float and return in float" << endl
         << endl;


    a = funcAverage_3(5, 2.4);


    printf("The average of these number is %f \n", a);
    printf("The average of these number is %.3f \n", a);

    cout << a << endl<<endl;





    cout<<"*************After using Function template ::*************"<<endl<<endl;

    a = funcAverage(5, 2);              //passed argument are integer but function template consider as float

    cout << "Average is 3.5 correct , Because argument of function are in Function Template ,and Function Template passed float that's why evalulate in float and return in float" << endl
         << endl;
    printf("The average of these number is %f \n", a); // format specifier is of float %.3f
    printf("The average of these number is %.3f \n", a);

    cout << a << endl<<endl;

    cout << "Average is 3.7 correct , Because argument of function are in Function Template , and Function Template passed float that's why evalulate in float and return in float" << endl
         << endl;

    a = funcAverage(5, 2.4); //passed argument are integer but function template consider as float

    printf("The average of these number is %f \n", a);
    printf("The average of these number is %.3f \n", a);

    cout << a << endl<<endl;





    cout <<"*************Swapping x and y usind Function template*************"<< endl;
    float x = 5, y = 7;
    cout<<"******Before swapping x and y  ::******"<<endl;
    cout <<"x = "<< x << endl
         <<"y = "<< y << endl;
    swapp(x, y);
    cout<<"******After swapping x and y  ::******"<<endl;
    cout <<"x = "<< x << endl
         <<"y = "<< y << endl;
    return 0;
}