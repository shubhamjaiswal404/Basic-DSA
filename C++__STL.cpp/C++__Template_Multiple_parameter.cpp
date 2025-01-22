// // //************************************** Without Using Template **************************************
// #include<iostream>
// using namespace std;

// class myClass{
//     public:
//     int data1;
//     char data2;

//     myClass(){
//         data1=2;
//         data2='A';
//     }

//     myClass(int a ,char b){
//         data1= a;
//         data2= b;
//     }


//     void display(){
//         cout<<"data1 = "<<this->data1<<endl<<"data2 = "<<this->data2<<endl;
//     }
// };

// int main(){
//     myClass Object;
//     myClass Object2(100,'Z');
//     Object.display();
//     Object2.display();
//     return 0;
// }

//************************************** Using Template with Multiple Parameter**************************************
#include<iostream>
using namespace std;

template <class T1,class T2>

class myClass{
    public:
    T1 data1;
    T2 data2;

    myClass(){
        data1=2;
        data2='A';
    }

    myClass(T1 a,T2 b){
        data1= a;
        data2= b;
    }
    void display(){
        cout<<"data1 = "<<this->data1<<endl<<"data2 = "<<this->data2<<endl;
    }
};

int main(){
    cout<<"****************** Using Template with Multiple Parameter ******************"<<endl<<endl;
    cout<<"********* myClass<int ,char> *********"<<endl;
    myClass<int ,char> Object;
    Object.display();
    cout<<"********* myClass<int ,char> *********"<<endl;
    myClass<int ,char> Object2(100,'Z');
    Object2.display();
    cout<<"********* myClass<int ,float> *********"<<endl;
    myClass<int ,float> Object3(100,3.14);
    Object3.display();
    cout<<"********* myClass<char ,float> *********"<<endl;
    myClass<char ,float> Object4('Z',3.14);
    Object4.display();
    
    return 0;
}

// NOTE::
// 
// Synatax for Multiple Template 
// 
// template <class T1, class T2>

// class myClass{
//      T1 data1;   -----> T1,T2 can be int ,float ,char
//      T2 data2;
//    public:
//      myClass(T1 a, T2 b)
//      {
//         data1= a;
//         data2= b;
// 
//        }    
//      }
// different class are used coming from same Templates
//  
//      myClass <int ,char > v1() ----> class for int 
//      myClass <char,float> v2() ----> class for float
//      myClass <double,char> v2()  ----> class for double
//      myClass <char,float,double,int> v2()  ----> class for char
// 
// 
// 

