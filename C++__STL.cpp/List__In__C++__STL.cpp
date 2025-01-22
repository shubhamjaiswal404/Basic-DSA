#include <iostream>
#include <list> //Header filer for list
using namespace std;

void display(list<int> &lst, int i)
{ // list<int>   Reference integer of list
   cout << endl
        << "*******Displaying Elements of List******* " << endl;
   list<int>::iterator it;
   cout << "Dereferencing pointer iterator will give value on which iterator is pointing  ---> *it {it ---> iterator ==> pointer} " << endl;
   cout << "List " << i << " --->   ";
   for (it = lst.begin(); it != lst.end(); it++)
   {  // Reference of start of the list ----> it=lst.begin()
      //                                                   // Reference of end of the list ----> it=lst.end()
      cout << *it << "   ";
   }
   cout << endl
        << endl;
}

int main()
{
   cout << "******************************List in STL ******************************" << endl;
   list<int> list_1; // List of 0 length

   // Creating List 1
   list_1.push_back(5); // member function of list {method::Add element at the end}
   list_1.push_back(7);
   list_1.push_back(1);
   list_1.push_back(9);
   list_1.push_back(18);

   list<int>::iterator iter;
   iter = list_1.begin();

   //                                                          // iter ---> iterator ==> pointer
   //                                                         // iter ---> name
   //                                                          // iter ---> now 5 will be on 1st position
   //                                                          //list_1.begin()  ---->   iterator will point 1st element
   //                                                          //begin() ---> reference member function of vector {method:: Return iterator to beginning }
   cout << "Dereferencing pointer iterator will give value on which iterator is pointing  ---> *iter  {iter ---> iterator ==> pointer} " << endl;
   cout << "List 1 --->   ";
   cout << *iter << "   ";
   iter++;
   cout << *iter << "   ";
   iter++;
   cout << *iter << "   ";
   iter++;
   cout << *iter << "   ";
   iter++;
   cout << *iter << "   " << endl
        << endl;

   list<int> list_2(3); // Empty List of size 7
                        // Creating List 2
   list<int>::iterator iter_2;
   iter_2 = list_2.begin();
   //                                                          // iter_2 ---> iterator ==> pointer
   //                                                         // iter_2 ---> name
   //                                                          // iter_2 ---> now 5 will be on 1st position
   //                                                          //list_2.begin()  ---->   iterator will point 1st element
   //                                                          //begin() ---> reference member function of vector {method:: Return iterator to beginning }

   *iter_2 = 45;
   iter_2++;
   *iter_2 = 6;
   iter_2++;
   *iter_2 = 9;
   iter_2++;

   display(list_2, 2);

   cout << endl
        << "***************Remove last element or Last element deleted from List 1 ***************" << endl;

   list_1.pop_back(); // member function of list {method:: Remove last element or Last element deleted  }
   display(list_1, 1);

   cout << endl
        << "***************Remove first element or First element deleted from List 1 ***************" << endl;
   list_1.pop_front(); // member function of list {method:: Remove first element or First element deleted  }
   display(list_1, 1);

   cout << endl
        << "***************Insert last element or Last element Inserted in List 1 {9 is added to list } ***************" << endl;
   list_1.push_back(9);
   display(list_1, 1);

   cout << endl
        << "***************Remove element, both 9 wil be deleted  ***************" << endl;
   list_1.remove(9); // member function of list {method:: Remove element satisfying specific criteria  }
   display(list_1, 1);

   cout << endl
        << "***************Insert last element or Last element Inserted in List 1 { 5 , 9, 18 is added to list } ***************" << endl;
   list_1.push_back(9);
   list_1.push_back(18);
   list_1.push_back(5);
   display(list_1, 1);

   //  sorting the list
   cout << endl
        << "***************Sort the element of List 1  ***************" << endl;
   list_1.sort(); // member function of list {method:: sort the element   }
   display(list_1, 1);

   cout << endl
        << "***************Sort the element of List 2  ***************" << endl;
   list_2.sort(); // member function of list {method:: sort the element   }
   display(list_2, 2);

   cout << "***************Merges two sorted lists are List 1 and List 2 ***************" << endl;
   display(list_1, 1);
   display(list_2, 2);
   list_1.merge(list_2); // member function of list {method:: merges two sorted lists    }
   cout << "***************List 1 After merging List 1 and List 2: ***************" << endl;
   display(list_1, 1);
   cout << "***************After merging the element of List 2 in List 1 , List 2 is empty***************" << endl;
   display(list_2, 2);

   // Reversing the list

   cout << "***************Reversing the list :: reverse the order of the element***************" << endl;
   list_1.reverse(); // member function of list {method:: reverse the order of the element    }
   cout << "***************List 1 After reversing : ***************" << endl;
   display(list_1, 1);

   return 0;
}
//
// Array ---> Fast Access but  Delection and Insertion is Slow
//
// List ---> list is bidirectional linear list use to insertion & deletion effective operation show
//     ---> Delection and Insertion is Fast
//     ---> No Fast Access {Traversal} , means array as index to access fast

