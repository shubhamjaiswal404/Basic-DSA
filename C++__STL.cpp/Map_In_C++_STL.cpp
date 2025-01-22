#include <iostream>
#include <string> //Header file for string
#include <map>    //Header file for map
using namespace std;

int main()
{

    // Creating Map of string to integer

    map<string, int> marksMap; //  Reference string of Map for key ,Reference integer of Map for value
    cout << "******************************Map in STL ******************************" << endl;

    // Insert some values into the map
    cout << "Inserting 3 value in the Map   Shubham: 98, Pankaj: 59 ,Ganesh: 2 " << endl;
    marksMap["Shubham"] = 98;
    marksMap["Pankaj"] = 59;
    marksMap["Ganesh"] = 2;

    map<string, int>::iterator iter;
    //                                                          // iter ---> iterator ==> pointer
    //                                                         // iter ---> name
    //                                                          // iter ---> now 5 will be on 1st position
    //                                                          //list_1.begin()  ---->   iterator will point 1st element
    //                                                          //begin() ---> reference member function of vector {method:: Return iterator to beginning }

    cout << endl
         << "*******Displaying Elements of Map******* " << endl;
    cout << "Dereferencing pointer iterator will give value on which iterator is pointing  ---> *iter.first { key } and  *iter.second { value } " << endl;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        //                                                            // Reference of start of the Map ----> iter = marksMap.begin()
        //                                                            // Reference of end of the Map ----> iter = marksMap.end()

        //  (*iter).first --->{1st element like shubham }      ,     (*iter).second --->{2nd element like 98 }
        cout << (*iter).first << "  ---->  " << (*iter).second << endl;
    }

    cout << endl
         << "Inserting 3 more value in the Map   Arvind: 100, Aryan: 80 ,Vaibhav: 420 " << endl;
    cout << endl
         << "*******Displaying Elements of Map******* " << endl;

    cout << "Dereferencing pointer iterator will give value on which iterator is pointing  ---> *iter.first { key } and  *iter.second { value } " << endl;
    marksMap.insert({{"Arvind", 100}, {"Aryan", 80}, {"Vaibhav", 42}}); // pair make dot insert --> insert element

    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        //  iter->first    --->{1st element like shubham }      ,     iter->second --->{2nd element like 98 }
        cout << iter->first << "  ---->  " << iter->second << endl; // arrow operator is used
    }

    cout << endl
         << "*************** Size of Map  ***************" << endl;
    cout << "The size is : " << marksMap.size() << endl; // member function of map {method:: Return the number of element }

    cout << endl
         << "*************** Maximum possible size of Map  ***************" << endl;
    cout << "The max size is : " << marksMap.max_size() << endl; // member function of map {method:: Return the maximum possible number of element }

    cout << endl
         << "***************Checking map is Empty or not {Empty: 1, Not-empty:0}  ***************" << endl;
    cout << "The empty return value is : " << marksMap.empty() << "       ---->means map is Not-empty " << endl; // member function of map {method:: check whether the container is empty }

    return 0;
}

//
// Map ---> {key - value pair}
// { key ---> value }
//
// Map is an associative array
//
// map <string , int> marks    //map<datatype of key ,datatype of value >