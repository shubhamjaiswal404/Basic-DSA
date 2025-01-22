// ***************Class Templates with Default Parameter ***************
#include<iostream>
using namespace std;

template<class T1 =int,class T2=float,class T3=char> //default argument like in function 

class myClass{
    public:
    T1 data1;
    T2 data2;
    T3 data3;
    myClass(T1 a, T2 b,T3 c){
        data1 = a;
        data2 = b;
        data3 = c;

    }
    void display(){
        cout<<"The value of data1 is "<<data1<<endl;
        cout<<"The value of data2 is "<<data2<<endl;
        cout<<"The value of data3 is "<<data3<<endl;
    }
};

int main(){
    cout<<"***************Class Templates with Default Parameter ***************"<<endl;
    // Empty arrgument in function like same in Template
    cout<<"*********Datatypes are int , float , char*********"<<endl<<endl;
    myClass<> Object(4,6.4,'g'); // default datatypes are int , float , char 
    Object.display();
    cout<<endl<<"*********Datatypes are float , char , char *********"<<endl<<endl;
    myClass<float,char,char> Object2(6.4,'M','g'); // customes datatypes are  float , char , char 
    Object2.display();
    cout<<endl<<"*********Datatypes are int , char , int*********"<<endl;
    myClass<int ,char,int> Object3(4,'g',100); // customes datatypes are int , char , int 
    Object3.display();
    return 0;
}