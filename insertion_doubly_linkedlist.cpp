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
    Node *previous;
    //  intializing constructor head to NULL
    Linkedlist() : head(NULL) {};

    Node *insertAtFirst(Node *head, int data);
    Node *insertAtIndex(Node *head, int data, int index);
    Node *insertAfterNode(Node *head, Node *pre, int data);
    Node *insertAtEnd(Node *head, int data);

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
             << "***********Before insertion Doubly Linkedlist***********::"
             << endl
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

void linkedlistTravesal(Node *firstNode)
{

    cout << "************Traversal (For understanding prefer while loop method below)************" << endl;
    Node *secondNode;
    Node *thirdNode;
    Node *fourthNode;
    Node *fifthNode;

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
    cout << "Address of thirdNode pointing fourthNode::" << thirdNode->next << "<----- same 4" << endl;
    cout << "value in fourthNode " << fourthNode->data << endl
         << endl;

    fifthNode = fourthNode->next;

    cout << "Address of fourthNode pointing thirdNode:: " << fifthNode->prev << "<----- same 4" << endl;
    cout << "Address of thirdNode pointing fourthNode::" << fourthNode->next << endl;
    cout << "value in fifthNode " << fifthNode->data << endl
         << endl;

    cout << "Address of fourthNode pointing NULL ::" << fifthNode->next << "<----- NULL " << endl;

    cout << endl
         << "***********After insertion Doubly Linkedlist***********::"
         << endl
         << "Doubly Linkedlist:: HEAD --->|   " << " |--->|  " << " |--->|   " << " |--->|   " << " |--->|   " << " |";
    cout << endl
         << "                 :: NULL <---|  " << firstNode->data << " |    | " << secondNode->data << " |    |" << thirdNode->data << "  |    | " << fourthNode->data << " |    | " << fifthNode->data << " |---> NULL";
    cout << endl
         << "                 ::      <---|   " << " |<---|  " << " |<---|   " << " |<---|   " << " |<---|   " << " |" << endl
         << endl;

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
    while (fifthNode != NULL)
    {
        cout << fifthNode->data << endl;
        fifthNode = fifthNode->prev;
    }
}

Node *Linkedlist::insertAtFirst(Node *head, int data)
{
    cout << "***********insertAtFirst***********" << endl;
    Node *newNode = new Node();
    newNode->next = head;
    head->prev = newNode;
    newNode->data = data;
    newNode->prev = NULL;
    return newNode;
}

Node *Linkedlist::insertAtIndex(Node *head, int data, int index)
{
    cout << "***********insertAtIndex***********" << endl;
    Node *newNode = new Node();
    Node *p = head;
    Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    newNode->next = p->next;
    newNode->prev = p;
    p->next = newNode;
    q->prev = newNode;
    newNode->data = data;
    return head;
}

Node *Linkedlist::insertAfterNode(Node *head, Node *previous, int data)
{
    cout << "***********insertAfterNode***********" << endl;
    Node *newNode = new Node();

    newNode->next = previous->next;
    previous->next = newNode;
    newNode->prev = previous;
    previous->next->next->prev = newNode; // ( previous--> newNode--> q =  previous->next->next         , q->prev = newNode )
    newNode->data = data;
    return head;
}

Node *Linkedlist::insertAtEnd(Node *head, int data)
{
    cout << "***********insertAtEnd***********" << endl;
    Node *newNode = new Node();
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->prev = p;
    newNode->next = NULL;
    newNode->data = data;
    return head;
}

int main()
{
    cout << "************insertion in Doubly Linkedlist ************" << endl;
    Linkedlist Object;
    Object.createLinkedlist(7, 8, 22, 11);
    // Object.head=Object.insertAtFirst(Object.head,45);
    // Object.head=Object.insertAtEnd(Object.head,45);
    Object.head=Object.insertAtIndex(Object.head,45,3);
    // Object.previous = Object.head->next->next;
    // Object.head = Object.insertAfterNode(Object.head, Object.previous, 45);
    linkedlistTravesal(Object.head);

    return 0;
}