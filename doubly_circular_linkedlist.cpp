#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
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
        firstNode->prev = fourthNode;
        firstNode->next = secondNode;

        // secondNode link with thirdNode
        secondNode->data = value2;
        secondNode->prev = firstNode;
        secondNode->next = thirdNode;

        // thirdNode link with fourthNode
        thirdNode->data = value3;
        thirdNode->prev = secondNode;
        thirdNode->next = fourthNode;

        // fourthNode link with NULL (linkedlist end or terminates)
        fourthNode->data = value4;
        fourthNode->prev = thirdNode;
        fourthNode->next = firstNode;

        cout << endl
             << "Circular doubly Linkedlist       ::          |---------" << "---------" << "----------" << "--------" << "-----|" << endl
             << "                                 ::          |         " << "         " << "          " << "        " << "     |" << endl
             << "                                 ::          |--->|  " << " |--->|  " << " |--->|   " << " |--->|   " << " |---|";
        cout << endl
             << "                                 ::    HEAD------>| " << firstNode->data << " |    | " << secondNode->data << " |    | " << thirdNode->data << " |    | " << fourthNode->data << " |  ";
        cout << endl
             << "                                 ::          |----|  " << " |<---|  " << " |<---|   " << " |<---|   " << " |<--|" << endl
             << "                                 ::          |         " << "         " << "          " << "        " << "     |" << endl
             << "                                 ::          |---------" << "---------" << "----------" << "--------" << "-----|" << endl
             << "address of head ( or fourthNode ) next and secondNode prev::" << firstNode << endl
             << "address of firstNode next and thridNode prev::" << secondNode << endl
             << "address of secondNode next and fourthNode prev::" << thirdNode << endl
             << "address of thirdNode next and firstNode prev::" << fourthNode << endl
             << endl;
    }
};

void linkedlistTravesal(struct Node *firstNode)
{

    cout << "************Traversal (For understanding prefer do-while loop method below)************" << endl;
    Node *secondNode;
    Node *thirdNode;
    Node *fourthNode;

    Node *ptr = firstNode;

    // cout<<first->next<<endl;
    cout << "Address of firstNode pointing fourthNode ::" << firstNode->prev << "<----- same 4 " << endl
         << endl;
    cout << "Address of head pointing firstNode ::" << firstNode << "<----- same 1 " << endl;
    cout << "value in firstNode " << firstNode->data << endl
         << endl;
    secondNode = firstNode->next;

    cout << "Address of secondNode pointing firstNode:: " << secondNode->prev << "<----- same 1 " << endl;
    cout << "Address of firstNode pointing secondNode:: " << firstNode->next << "<----- same 2 " << endl;
    cout << "value in secondNode " << secondNode->data << endl
         << endl;
    thirdNode = secondNode->next;

    cout << "Address of thirdNode pointing secondNode:: " << thirdNode->prev << "<----- same 2 " << endl;
    cout << "Address of secondNode pointing thirdNode:: " << secondNode->next << "<----- same 3 " << endl;
    cout << "value in thirdNode " << thirdNode->data << endl
         << endl;

    fourthNode = thirdNode->next;

    cout << "Address of fourthNode pointing thirdNode:: " << fourthNode->prev << "<----- same 3" << endl;
    cout << "Address of thirdNode pointing fourthNode::" << thirdNode->next << "<----- same 4 " << endl;
    cout << "value in fourthNode " << fourthNode->data << endl
         << endl;

    cout << "Address of fourthNode pointing firstNode ::" << fourthNode->next << "<----- same 1  " << endl
         << endl;

    cout << "************Traversal (do-while loop method)************" << endl;

    cout << endl
         << "***************Forward traversal in doubly linkedlist***************" << endl;

    do
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != firstNode);

    cout << endl;
    cout << "***************Backward traversal in doubly linkedlist***************" << endl;

    ptr = fourthNode; // initializing ptr

    do
    {
        cout << ptr->data << endl;
        ptr = ptr->prev;
    } while (ptr != fourthNode);

}

int main()
{
    cout << "************Circular Doubly Linkedlist Creation and Traversal************" << endl;
    Linkedlist Object;
    Object.createLinkedlist(7, 8, 22, 11);
    linkedlistTravesal(Object.head);

    return 0;
}