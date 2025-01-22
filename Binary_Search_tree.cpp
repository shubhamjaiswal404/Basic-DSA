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
    Node *createTree_1();
    Node *createTree_2();
    Node *createNode(int value);
    void preOrderTraversal(Node *root);
    void InOrderTraversal(Node *root);
    void postOrderTraversal(Node *root);
    int isBST(Node *root);
};

Node *Tree::createNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

Node *Tree::createTree_1()
{
    Node *p = createNode(9);
    Node *p1 = createNode(4);
    Node *p2 = createNode(11);
    Node *p3 = createNode(2);
    Node *p4 = createNode(7);
    Node *p5 = createNode(5);
    Node *p6 = createNode(8);
    Node *p7 = createNode(15);
    Node *p8 = createNode(14);

    // p1<--p-->p2;
    p->left = p1;
    p->right = p2;

    // p3<--p1-->p4;

    p1->left = p3;
    p1->right = p4;

    // p5<--p4-->p6;

    p4->left = p5;
    p4->right = p6;

    // NULL<--p2-->p7;
    p2->right = p7;

    // p8<--p7-->NULL;
    p7->left = p8;

    return p;
}

Node *Tree::createTree_2()
{
    Node *q = createNode(9);
    Node *q1 = createNode(4);
    Node *q2 = createNode(11);
    Node *q3 = createNode(2);
    Node *q4 = createNode(7);
    Node *q5 = createNode(5);
    Node *q6 = createNode(8);
    Node *q7 = createNode(15);
    Node *q8 = createNode(40);
    Node *q9 = createNode(14);

    // q1<--q-->q2;
    q->left = q1;
    q->right = q2;

    // q3<--q1-->q4;

    q1->left = q3;
    q1->right = q4;

    // q5<--q4-->q6;

    q4->left = q5;
    q4->right = q6;

    // NULL<--q2-->q7;
    q2->right = q7;

    // q8<--q7-->q9;
    q7->left = q8;
    q7->right = q9;

    return q;
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

int main()
{
    Tree Object;
    Node *root_p = Object.createTree_1();
    Node *root_q = Object.createTree_2();

    cout << "******************Binary Search Tree******************" << endl
         << endl;

    cout << "NOTE::: Inorder Traversal of a BST gives an Ascending Sorted array" << endl
         << endl;

    if (Object.isBST(root_p))
    {
        cout << "Tree 1 is Binary Search Tree  " << endl;
    }
    else
    {
        cout << "Tree 1 is NOT a Binary Search Tree  " << endl;
    }

    cout << "******InOrder Traversal of Tree 1 ************" << endl;
    Object.InOrderTraversal(root_p);
    cout << "    ---------------> Sorted " << endl
         << endl;

    if (Object.isBST(root_q))
    {
        cout << "Tree 2 is Binary Search Tree  " << endl;
    }
    else
    {
        cout << "Tree 2 is NOT a Binary Search Tree  " << endl;
    }

    cout << "******InOrder Traversal of Tree 2 ************" << endl;
    Object.InOrderTraversal(root_q);
    cout << "    ---------------> Not Sorted " << endl;

    return 0;
}

//
// Binary Search Tree (BST):: It is a type of Binary tree
// BST::search in the efficient Time Complexity ==> Best case :: O(1) , Average case :: O(log n) , Waste case :: O(n)
// Properties::
// 1) All nodes of the left subtree are lesser
// 2) All nodes of the right subtree are greater
// 3) Left and Right subtree are also BST
// 4) There are no duplicate node {same value Two node are not there}

// Leftsubtree < Root < Rightsubtree

// 1  <  7  >  6    ------> Not a BST
//                       7
//                      / |   ---> Is this a BST ---> NO
//                     1  6    {reason:: 7 > 6  }
//
//
// 7  >  1  <  6    ------> Not a BST
//                       1
//                      / |   ---> Is this a BST ---> NO
//                     7  6    {reason:: 7 > 1  }

// 7  >  6  <  1    ------> Not a BST
//                       6
//                      / |   ---> Is this a BST ---> NO
//                     7  1    {reason:: 7 > 6 and 6 > 1 }

// 1  <  6  <  7    ------> BST
//                       6
//                      / |   ---> Is this a BST ---> YES
//                     1  7

//
// NOTE::: Inorder Traversal of a BST gives an Ascending Sorted array
//
//******InOrder Traversal ************
//  Leftsubtree---->Root---->Rightsubtree
//
//                         9
//                       /    |             ==> 2 4 5 7 8 9 11 14 15 ==> Ascending Sorted array after inorder traversal Of BST
//                      4     11
//                    /  |      |
//                   2   7     15
//                      / |    /
//                     5  8   14
//
//                 Binary Search Tree - 1

//******InOrder Traversal ************
//  Leftsubtree---->Root---->Rightsubtree
//
//                         9
//                       /    |             ==> 2  4  5  7  8  9  11  40  15  14 ==> NOT Ascending Sorted array after inorder traversal Of BST
//                      4     11
//                    /  |      |
//                   2   7     15
//                      / |    / |
//                     5  8   40  14
//
//                 Binary Search Tree - 2
