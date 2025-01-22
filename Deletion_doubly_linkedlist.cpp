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

    Node *deleteFirst(Node *head);
    Node *deleteAtIndex(Node *head, int index);
    Node *deleteAfterNode(Node *head, int value);
    Node *deleteAtLast(Node *head);

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
             << "***********Before deletion Doubly Linkedlist***********::"
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
    cout << "Address of secondNode pointing thirdNode:: " << secondNode->next << endl;
    cout << "value in thirdNode " << thirdNode->data << endl
         << endl;

    cout << "Address of thirdNode pointing NULL ::" << thirdNode->next << "<----- NULL " << endl;

    cout << endl
         << "***********After deletion Doubly Linkedlist***********::"
         << endl
         << "Doubly Linkedlist:: HEAD --->|   " << " |--->|   " << " |--->|   " << " |--->  ";
    cout << endl
         << "                 :: NULL <---|  " << firstNode->data << " |    | " << secondNode->data << "  |    |" << thirdNode->data << "  |---> NULL";
    cout << endl
         << "                 ::      <---|   " << " |<---|   " << " |<---|   " << " |<---   " << endl
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
    while (thirdNode != NULL)
    {
        cout << thirdNode->data << endl;
        thirdNode = thirdNode->prev;
    }
}

Node *Linkedlist::deleteFirst(Node *head)
{
    cout << "***********deleteFirst***********" << endl;
    Node *newNode = head;
    head = head->next;
    head->prev = NULL;
    delete newNode;
    return head;
}

Node *Linkedlist::deleteAtLast(Node *head)
{
    // Note::same method is used to delete element in singly linkedlist
    cout << "***********deleteAtEnd***********" << endl;
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
    return head;
}

Node *Linkedlist::deleteAtIndex(Node *head, int index)
{
    cout << "***********deleteAtIndex***********" << endl;
    Node *p = head;
    Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;
    delete q;
    return head;
}

Node *Linkedlist::deleteAfterNode(Node *head, int value)
{ // NOTE :: value is given
    cout << "***********deleteAfterNode***********" << endl;
    Node *p = head;
    Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data = value)
    {
        p->next = q->next;
        q->next->prev = p;
        delete q;
    }
    return head;
}

int main()
{
    cout << "************deletion in Doubly Linkedlist ************" << endl;
    Linkedlist Object;
    Object.createLinkedlist(7, 8, 22, 11);
    Object.head=Object.deleteFirst(Object.head);
    // Object.head=Object.deleteAtLast(Object.head);
    // Object.head=Object.deleteAtIndex(Object.head,1);
    // Object.head = Object.deleteAfterNode(Object.head, 22);
    linkedlistTravesal(Object.head);

    return 0;
}