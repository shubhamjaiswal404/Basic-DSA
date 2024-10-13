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

    Node *insertAtFirst(Node *head, int data);
    Node *insertAtIndex(Node *head, int data, int index);
    Node *insertAtEnd(Node *head, int data);
    void linkedlistTravesal(Node *firstNode);

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

Node *Linkedlist ::insertAtFirst(Node *head, int data)
{

    cout << "**********insertAtFirst**********" << endl
         << endl;

    Node *fifthNode = new Node();

    fifthNode->data = data;

    Node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = fifthNode;
    fifthNode->next = head;
    head = fifthNode;

    return head;
}

Node *Linkedlist ::insertAtEnd(Node *head, int data)
{

    cout << "**********insertAtEnd**********" << endl
         << endl;

    Node *fifthNode = new Node();

    fifthNode->data = data;

    Node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = fifthNode;
    fifthNode->next = head;

    return head;
}

Node *Linkedlist::insertAtIndex(Node *head, int data, int index)
{
    cout << "***********insertAtIndex***********" << endl
         << endl;
    Node *fifthNode = new Node();
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    fifthNode->next = p->next;
    p->next = fifthNode;
    fifthNode->data = data;
    return head;
}

void Linkedlist ::linkedlistTravesal(Node *firstNode)
{

    cout << "************Traversal (For understanding prefer while loop method below)************" << endl;
    Node *secondNode;
    Node *thirdNode;
    Node *fourthNode;
    Node *fifthNode;

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

    fifthNode = fourthNode->next;
    cout << "Address of head pointing fifthNode ::" << fifthNode << endl;
    cout << "value in fifthNode " << fifthNode->data << endl
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

    cout << endl
         << "Linkedlist:: HEAD --->" << firstNode->data << "--->" << secondNode->data << "--->" << thirdNode->data << "--->" << fourthNode->data << "--->" << fifthNode->data << "---| " << endl;
    cout << "                      ^                          | " << endl;
    cout << "                      |                          |" << endl;
    cout << "                      |--------------------------|" << endl
         << endl;
    cout << "address of head ::" << firstNode << " <--- same " << endl
         << "address of firstNode::" << secondNode << endl
         << "address of secondNode::" << thirdNode << endl
         << "address of thirdNode::" << fourthNode << endl
         << "address of fourthNode:" << fifthNode << endl
         << "address of fifthNode::" << fifthNode->next << " <--- same " << endl
         << endl;
}

int main()
{
    cout << "************Insertion in Circular linkedlist ************" << endl;
    Linkedlist Object;
    Object.createLinkedlist(7, 8, 22, 11);
    // Object.head=Object.insertAtFirst(Object.head,54);
    //  Object.head=Object.insertAtEnd(Object.head,54);
    Object.head = Object.insertAtIndex(Object.head, 54, 2);
    Object.linkedlistTravesal(Object.head);

    return 0;
}

// Insertion in Circular linkedlist
//
//  Circular Linkedlist Before ::

//     HEAD--->|7 (0x10019e8)|--->|7|8 (0x10019f8) |--->|8|22 (0x1001a08)|--->|22|11 (0x1001a18)|--->|11| head (0x10019e8)|----|
//           ^                                                                                                            |
//           |                                                                                                            |
//           |------------------------------------------------------------------------------------------------------------|

//
//    HEAD  --->  firstNode         ------>         secondNode        ------>         thirdNode     ------>           fourthNode
//                  ^                                                                                                    |
//                  |                                                                                                    |
//                  | ---------------------------------------------------------------------------------------------------|
//
//

//  Circular Linkedlist After Insertion :: insertAtFirst

//     HEAD--->|54 (0x1001a28)|--->|54|7 (0x10019e8) |--->|7|8 (:0x10019f8) |--->|8|22 (0x1001a08)|--->|22|11 (0x1001a18)|--->|11| head (0x1001a28)|----|
//           ^                                                                                                            |
//           |                                                                                                            |
//           |------------------------------------------------------------------------------------------------------------|

//
//    HEAD  ---|  firstNode         ------>         secondNode        ------>         thirdNode     ------>           fourthNode
//             |      ^                                                                                                    |
//             |      |                                                                                                    |
//             |      |                   |--------------------------------------------------------------------------------|
//             |      |                   |
//             |      |                   |
//             |---> fifthNode <----------|

//
//    HEAD  --->fifthNode        ------>              firstNode         ------>         secondNode        ------>         thirdNode     ------>           fourthNode
//                  ^                                                                                                                                        |
//                  |                                                                                                                                        |
//                  | ---------------------------------------------------------------------------------------------------------------------------------------|
//
//

//  Circular Linkedlist After Insertion :: insertAtEnd

//     HEAD--->|7 (0x10319e8)|--->|7|8 (0x10319f8) |--->|8|22 (0x1031a08)|--->|22|11 (0x1031a18)|--->|11| 54 (0x1031a28)|---->|54| head (0x10319e8) ||
//                  ^                                                                                                            |
//                  |                                                                                                            |
//                  |------------------------------------------------------------------------------------------------------------|

//
//    HEAD  --->  firstNode         ------>         secondNode        ------>         thirdNode     ------>           fourthNode
//                   ^                                                                                                    |
//                   |                                                                                                    |
//                   |                   |--------------------------------------------------------------------------------|
//                   |                   |
//                   |                   |
//                  fifthNode <----------|

//
//    HEAD  ---->  firstNode         ------>         secondNode        ------>         thirdNode     ------>           fourthNode          --->fifthNode
//                  ^                                                                                                                               |
//                  |                                                                                                                               |
//                  | ------------------------------------------------------------------------------------------------------------------------------|
//

//  Circular Linkedlist After Insertion :: insertAtIndex

//     HEAD--->|7 (0x8919e8)|--->|7|8 (0x8919f8) |--->|8|54 (0x891a28)|--->|54|22 (0x891a08) |--->|22|11 (0x891a18)|--->|11| head (0x8919e8 )|----|
//           ^                                                                                                            |
//           |                                                                                                            |
//           |------------------------------------------------------------------------------------------------------------|

//
//    HEAD  --->  firstNode         ------>         secondNode        ---x--->       |------->  thirdNode     ------>           fourthNode
//             |                                         |                           |                                               |
//             |                                         |                           |                                               |
//             |                                         |-------> fifthNode  -------|                                               |
//             |                                                                                                                     |
//             |---------------------------------------------------------------------------------------------------------------------|

//
//    HEAD  ---> firstNode       ------>              secondNode          ------>         fifthNode       ------>         thirdNode     ------>           fourthNode
//                  ^                                                                                                                                        |
//                  |                                                                                                                                        |
//                  | ---------------------------------------------------------------------------------------------------------------------------------------|
//
//
//
