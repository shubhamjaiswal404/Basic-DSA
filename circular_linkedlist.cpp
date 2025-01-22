#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linkedlist
{

    int value1, value2, value3, value4;

public:
    Node *head;
    //  intializing constructor head to NULL
    Linkedlist() : head(NULL) {};

    void createLinkedlist(int value1, int value2, int value3, int value4)
    {
        // Creating Nodes and Allocate memory for Node in linkedlist
        Node *firstNode = new Node();
        Node *secondNode = new Node();
        Node *thirdNode = new Node();
        Node *fourthNode = new Node();

        // head link with firstNode (linkedlist start)
        head = firstNode;

        // firstNode link with secondNode
        firstNode->data = value1;
        firstNode->next = secondNode;

        // secondNode link with thirdNode
        secondNode->data = value2;
        secondNode->next = thirdNode;

        // thirdNode link with fourthNode
        thirdNode->data = value3;
        thirdNode->next = fourthNode;

        // fourthNode link with HEAD (linkedlist never end or terminates)
        fourthNode->data = value4;
        fourthNode->next = firstNode;

        cout << endl
             << "Linkedlist:: HEAD --->" << firstNode->data << "--->" << secondNode->data << "--->" << thirdNode->data << "--->" << fourthNode->data << "---| " << endl;
        cout << "                      ^                    | " << endl;
        cout << "                      |                    |" << endl;
        cout << "                      |--------------------|" << endl
             << endl;
        cout << "address of head ::" << firstNode << " <--- same " << endl
             << "address of firstNode::" << secondNode << endl
             << "address of secondNode::" << thirdNode << endl
             << "address of thirdNode::" << fourthNode << endl
             << "address of fourthNode::" << fourthNode->next << " <--- same " << endl
             << endl;
    }
};

void linkedlistTravesal(Node *firstNode)
{

    cout << "************Traversal (For understanding prefer while loop method below)************" << endl;
    Node *secondNode;
    Node *thirdNode;
    Node *fourthNode;
    Node *ptr = firstNode; // firstNode is head [pointer]

    // cout<<first->next<<endl;
    cout << "Address of head pointing firstNode ::" << firstNode << endl;
    cout << "value in firstNode " << firstNode->data << endl
         << endl;
    secondNode = firstNode->next;

    cout << "Address of firstNode pointing secondNode:: " << secondNode << endl;
    cout << "value in secondNode " << secondNode->data << endl
         << endl;
    thirdNode = secondNode->next;

    cout << "Address of secondNode pointing thirdNode:: " << thirdNode << endl;
    cout << "value in thirdNode " << thirdNode->data << endl
         << endl;

    fourthNode = thirdNode->next;

    cout << "Address of thirdNode pointing fourthNode::" << fourthNode << endl;
    cout << "value in fourthNode " << fourthNode->data << endl
         << endl;

    cout << "************Traversal (while loop and do-while method)************" << endl;

    cout << "***********using While loop***********" << endl;
    cout << "Element of Circular linkedlist :: " << ptr->data << endl;
    ptr = ptr->next;
    while (ptr != firstNode)
    {
        cout << "Element of Circular linkedlist :: " << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << endl;

    cout << "***********using Do-While loop(prefer do-while loop in circular traversal)***********" << endl;

    do
    {
        cout << "Element of Circular linkedlist :: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != firstNode);
    cout << endl;
}

int main()
{
    cout << "************Circular linkedlist Creation and Traversal************" << endl;
    Linkedlist Object;
    Object.createLinkedlist(7, 8, 22, 11);
    linkedlistTravesal(Object.head);

    return 0;
}

// Circular linkedlist creation  + traversal
//
//  Circular Linkedlist

//     HEAD--->|address of 7(0xf519e0)|--->|7| address of 8(0xf51558) |--->|8| address of 22(0xf51568)|--->|22| address of 11(0xf51578)|--->|11| address of head|----|
//           ^                                                                                                                                                       |
//           |                                                                                                                                                       |
//           |-------------------------------------------------------------------------------------------------------------------------------------------------------|

//
//                             HEAD  --->  firstNode         ------>         secondNode        ------>         thirdNode     ------>           fourthNode
//                                             ^                                                                                                    |
//                                             |                                                                                                    |
//                                             | ---------------------------------------------------------------------------------------------------|
//
//