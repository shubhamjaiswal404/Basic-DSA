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
        firstNode->prev = NULL;
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
        fourthNode->next = NULL;

        cout << endl
             << "Doubly Linkedlist:: HEAD --->|  " << " |--->|  " << " |--->|   " << " |--->|   " << " |";
        cout << endl
             << "                 :: NULL <---| " << firstNode->data << " |    | " << secondNode->data << " |    | " << thirdNode->data << " |    | " << fourthNode->data << " |---> NULL";
        cout << endl
             << "                 ::          |  " << " |<---|  " << " |<---|   " << " |<---|   " << " |" << endl
             << "address of head and secondNode prev::" << firstNode << endl
             << "address of firstNode next and thridNode prev::" << secondNode << endl
             << "address of secondNode next and fourthNode prev::" << thirdNode << endl
             << "address of thirdNode next ::" << fourthNode << endl
             << endl

             << "address of firstNode prev and fourthNode next is NULL::" << firstNode->prev << " and " << fourthNode->next << endl;
    }
};

void linkedlistTravesal(struct Node *firstNode)
{

    cout << "************Traversal (For understanding prefer while loop method below)************" << endl;
    struct Node *secondNode;
    struct Node *thirdNode;
    struct Node *fourthNode;

    // cout<<first->next<<endl;
    cout << "Address of firstNode pointing NULL ::" << firstNode->prev << "<----- NULL " << endl
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
    cout << "Address of thirdNode pointing fourthNode::" << thirdNode->next << endl;
    cout << "value in fourthNode " << fourthNode->data << endl
         << endl;

    cout << "Address of fourthNode pointing NULL ::" << fourthNode->next << "<----- NULL " << endl;

    cout << "************Traversal (while loop method)************" << endl;

    cout << endl
         << "***************Forward traversal in doubly linkedlist***************" << endl;
    while (firstNode != NULL)
    {
        cout << firstNode->data << endl;
        firstNode = firstNode->next;
    }

    cout << endl
         << "***************Backward traversal in doubly linkedlist***************" << endl;
    while (fourthNode != NULL)
    {
        cout << fourthNode->data << endl;
        fourthNode = fourthNode->prev;
    }
}

int main()
{
    cout << "************Doubly Linkedlist Creation and Traversal************" << endl;
    Linkedlist Object;
    Object.createLinkedlist(7, 8, 22, 11);
    linkedlistTravesal(Object.head);

    return 0;
}