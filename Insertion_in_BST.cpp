#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Node *createTree();
    Node *createNode(int value);
    void preOrderTraversal(Node *root);
    void InOrderTraversal(Node *root);
    void postOrderTraversal(Node *root);
    int isBST(Node *root);
    Node *search_Iterative(Node *root, int key);
    void insert(Node* root, int key);
};

Node *Tree::createNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

Node *Tree::createTree()
{
    Node *p = createNode(8);
    Node *p1 = createNode(3);
    Node *p2 = createNode(10);
    Node *p3 = createNode(1);
    Node *p4 = createNode(6);
    Node *p5 = createNode(4);
    Node *p6 = createNode(7);
    Node *p7 = createNode(14);
    Node *p8 = createNode(13);

    // p1<--p-->p2;
    p->left = p1;
    p->right = p2;

    // p3<--p1-->p4;

    p1->left = p3;
    p1->right = p4;

    // NULL<--p2-->p7;

    p2->right = p7;

    // p8<--p2-->NULL;
    p7->left  = p8;

    // p5<--p4-->p6;

    p4->left = p5;
    p4->right = p6;



    return p;
}

void Tree::InOrderTraversal(Node *root)
{
    if (root != NULL)
    {

        InOrderTraversal(root->left);
        cout << root->data << "  ";
        InOrderTraversal(root->right);
    }
}

int Tree::isBST(Node *root)
{
    if (root != NULL)
    {

        static Node *prev = NULL; // Note static :: value not differe for different call

        if (!isBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }

    else
    {
        return 1; // Empty tree is assumed as BST
    }
}


Node *Tree::search_Iterative(Node *root, int key)
{
    while (root != NULL)
    {

        if (key == root->data)
        {                // key is equal to root
            return root; // element found
        }
        else if (key < root->data)
        {                      // key is lesser then root
            root = root->left; // go for left subtree
        }
        else
        {                       // key is greater then root
            root = root->right; // go for right subtree
        }
    }
    return NULL; // element not found
}

void Tree::insert(Node* root, int key){

    Node* prev_Node = NULL;
// searching of Duplicate Node
    while(root!=NULL){
        prev_Node=root;
        if(key==root->data){
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root = root->right;
        }
        
    }
// After not founding Duplicate node  
        
    Node* new_Node  = createNode(key);      // Creating node for insertion 

    if(key<prev_Node->data){                // searching stop at Insertion position because we search for 9 and not found 9 but found       
//                                              perfect position for insertion 9 
        prev_Node->left = new_Node;
    }
    else{
        prev_Node->right = new_Node; 
    }
}

int main()
{
    Tree Object;
    Node *root = Object.createTree();

    cout << "******************Insertion in Binary Search Tree******************" << endl
         << endl;
    cout<<"******************Before insertion ::************************************"<<endl;

    cout << "NOTE::: Inorder Traversal of a BST gives an Ascending Sorted array" << endl
         << endl;

    if (Object.isBST(root))
    {
        cout << "Tree 1 is Binary Search Tree  " << endl;
    }
    else
    {
        cout << "Tree 1 is NOT a Binary Search Tree  " << endl;
    }

    cout<<"Searching for ----> 9 "<<endl;
    
    cout << "******InOrder Traversal of BST ************" << endl;
    Object.InOrderTraversal(root);
    cout << "    ---------------> Sorted " << endl
         << endl;

    cout << endl
         << endl;

    cout << "************Iterative Search in BST ************" << endl;
    // Iterative Approach is used below
    Node *m = Object.search_Iterative(root, 9);
    if (m != NULL)
    {
        cout << "Found :: " << m->data << endl;
        cout << "Element found in BST" << endl;
    }
    else
    {
        cout << "Element not found in BST " << endl;
    }




    Object.insert(root,9);      // insertion of key == 9 




    cout<<"******************After insertion ::************************************"<<endl<<endl;
    cout << "NOTE::: Inorder Traversal of a BST gives an Ascending Sorted array" << endl
         << endl;

    

    cout << "******InOrder Traversal of BST************" << endl;
    Object.InOrderTraversal(root);
    cout << "    ---------------> Sorted " << endl
         << endl;

    cout << endl
         << endl;
    cout << "************Iterative Search in BST ************" << endl;
    // Iterative Approach is used below
    Node *n = Object.search_Iterative(root, 9);
    if (n != NULL)
    {
        cout << "Found :: " << n->data << endl;
        cout << "Element found in BST" << endl;
    }
    else
    {
        cout << "Element not found in BST " << endl;
    }

    return 0;
}
 
//Insertion in a Binary Search Tree
//BST ----> NO Duplicates Allowed
// 
//Before Insertion Check the element by searching 
//{ Search 9 is already or not } and {Search where to insert }  
// 
//                          8  -----> prev             
//                       /    |            
//                      3     10
//                    /  |      |
//                   1   6     14
//                      / |    /
//                     4  7   13
//
// After searching 9 in BST ,we not found 9 . That means we can insert 9 in BST
// 
//                          8    --> new_Node > prev ----> 9 > 8 // go to right subtree           
//                       /    |            
//                          |--------|-
//                      3   |  10    |
//                    /  |  |    |   |
//                   1   6  |   14   |
//                      / | |   /    |
//                     4  7 |  13    |
//                          |--------|

// Right-subtree 
// 
//                     
//                       10 ---> prev   
//                      /  |            --> new_Node < prev ----> 9 < 10 // go to left subtree  
//No leftsubtree  --> NULL  14   
//                        /    
//                      13    
//                     

// Search is over insert new_Node here 
//                     
//                       10 ---> prev   
//                      /  |            --> new_Node < prev ----> 9 < 10 // go to left subtree  
//         prefect  -->9   14   
//        position         /    
//       for insertion   13    
//
//  After insertion of 9  
//                          8          
//                       /     |            
//                      3      10
//                    /  |    /  |
//                   1   6   9   14
//                      / |      /
//                     4  7     13
//       
// 
// NOTE:: We Searching for 9 in BST and we Not found 9 but position of 9 by Seraching , searching play important role in insertion of BST
              

