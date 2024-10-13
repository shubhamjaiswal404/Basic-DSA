#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class Linkedlist{

     int value1,value2,value3,value4;
   public:
     Node*head;
    //  intializing constructor head to NULL
        Linkedlist():head(NULL){};
        void linkedlistTravesal(Node*head);
        Node* deleteFirst(Node* head);
        Node* deleteAtLast(Node* head);
        Node* deleteAfterNode(Node* head,int value);
        Node* deleteAtIndex(Node* head,int index);

    
       void createLinkedlist(int value1,int value2,int value3,int value4) { 
        //Creating Nodes and Allocate memory for Node in linkedlist
        Node* firstNode = new Node(); 
        Node* secondNode = new Node(); 
        Node* thirdNode = new Node(); 
        Node* fourthNode = new Node(); 

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

        // fourthNode link with NULL (linkedlist end or terminates)
        fourthNode->data = value4;      
        fourthNode->next = NULL;       
                    
    cout<<endl<<"Linkedlist Before Deletion:: HEAD --->"<<firstNode->data<<"--->"<<secondNode->data<<"--->"<<thirdNode->data<<"--->"<<fourthNode->data<<"---> NULL"<<endl;
    cout<<"address of head ::"<<firstNode<<endl
    <<"address of firstNode::"<<secondNode<<endl
    <<"address of secondNode::"<<thirdNode<<endl
    <<"address of thirdNode::"<<fourthNode<<endl<<endl;
      
    }
};

Node* Linkedlist::deleteFirst(Node*head){
    cout<<"***********deleteFirst***********"<<endl;
    Node*newNode=head;
    head=head->next;
    delete newNode;
    return head;
}

Node* Linkedlist::deleteAtIndex(Node*head,int index){
    cout<<"***********deleteAtIndex***********"<<endl;
    Node*p=head;
    Node*q=head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    delete q;
    return head;
}

Node* Linkedlist::deleteAfterNode(Node*head,int value){ // NOTE :: value is given 
    cout<<"***********deleteAfterNode***********"<<endl;
    Node*p=head;
    Node*q=head->next;

    while(q->data!=value &&q->next!=NULL){
        p=p->next;
        q=q->next;
    }

    if(q->data=value){
        p->next=q->next;
        delete q;
    }
    return head;
}

Node* Linkedlist::deleteAtLast(Node*head){
    cout<<"***********deleteAtEnd***********"<<endl;
    Node*p=head;
    Node*q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    delete q;
    return head;
}





void Linkedlist :: linkedlistTravesal(Node*firstNode){
    
    Node*secondNode;
    Node*thirdNode;
    
    cout<<endl<<"************Traversal (For understanding prefer while loop method below)************"<<endl;
    // cout<<first->next<<endl;
    cout<<"Address of head pointing firstNode ::"<<firstNode<<endl;
    cout<<"value in firstNode "<<firstNode->data<<endl<<endl;
    secondNode=firstNode->next;

    cout<<"Address of firstNode pointing secondNode:: "<<secondNode<<endl;
    cout<<"value in secondNode "<<secondNode->data<<endl<<endl;
    thirdNode=secondNode->next;

    cout<<"Address of secondNode pointing thirdNode:: "<<thirdNode<<endl;
    cout<<"value in thirdNode "<<thirdNode->data<<endl<<endl;

   

    cout<<endl<<"Linkedlist After Deletion:: HEAD --->"<<firstNode->data<<"--->"<<secondNode->data<<"--->"<<thirdNode->data<<"---> NULL"<<endl<<endl;

    cout<<"************Traversal (while loop method)************"<<endl;

    while(firstNode!=NULL){
    cout<<firstNode->data<<endl;
    firstNode=firstNode->next;

    }

}


int main(){
    cout<<"************Deletion in Linkedlist ************"<<endl;
    Linkedlist Object;

    
    Object.createLinkedlist(7,8,22,11);
    Object.head=Object.deleteFirst(Object.head);
    // Object.head=Object.deleteAtLast(Object.head);
    // Object.head=Object.deleteAtIndex(Object.head,2);
    // Object.head=Object.deleteAfterNode(Object.head,22); //   //NOTE:: Node value is given 
    Object.linkedlistTravesal(Object.head);


    cout<<"NOTE:: Only insertion functions are introduce in yesterday code and Linkedlist creation "<<endl;

    

    return 0;
}



// ************Deletion in Linkedlist ************

// ***********deleteFirst***********
// Linkedlist Before Deletion:: HEAD --->7--->8--->22--->11---> NULL
// Linkedlist After Deletion:: HEAD --->8--->22--->11---> NULL

// ***********deleteAtEnd***********
// Linkedlist Before Deletion:: HEAD --->7--->8--->22--->11---> NULL
// Linkedlist After Deletion:: HEAD --->7--->8--->22---> NULL

// ***********deleteAtIndex***********
// Linkedlist Before Deletion:: HEAD --->7--->8--->22--->11---> NULL
// Linkedlist After Deletion:: HEAD --->7--->8--->11---> NULL

// ***********deleteAfterNode***********
// Linkedlist Before Deletion:: HEAD --->7--->8--->22--->11---> NULL
// Linkedlist After Deletion:: HEAD --->7--->8--->11---> NULL


