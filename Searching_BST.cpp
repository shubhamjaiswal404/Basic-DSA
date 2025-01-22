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
    Node *search_Recursive(Node *root, int key);
    Node *search_Iterative(Node *root, int key);
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
    Node *p = createNode(50);
    Node *p1 = createNode(40);
    Node *p2 = createNode(60);
    Node *p3 = createNode(20);
    Node *p4 = createNode(45);
    Node *p5 = createNode(55);
    Node *p6 = createNode(70);

    // p1<--p-->p2;
    p->left = p1;
    p->right = p2;

    // p3<--p1-->p4;

    p1->left = p3;
    p1->right = p4;

    // p5<--p4-->p6;

    p2->left = p5;
    p2->right = p6;

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

Node *Tree::search_Recursive(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL; // element not found
    }
    if (key == root->data)
    {                // key is equal to root
        return root; // element found
    }
    else if (key < root->data)
    {                                             // key is lesser then root
        return search_Recursive(root->left, key); // recursive for left subtree
    }
    else
    {                                              // key is greater then root
        return search_Recursive(root->right, key); // recursive for right subtree
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

int main()
{
    Tree Object;
    Node *root = Object.createTree();

    cout << "******************Binary Search Tree******************" << endl
         << endl;

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

    cout << "******InOrder Traversal of Tree 1 ************" << endl;
    Object.InOrderTraversal(root);
    cout << "    ---------------> Sorted " << endl
         << endl;

    cout << endl
         << endl;
    cout << "************Recursive Search in BST ************" << endl;

    // Recursive Approach is used below

    Node *n = Object.search_Recursive(root, 50);
    if (n != NULL)
    {
        cout << "Found :: " << n->data << endl;
        cout << "Element found in BST " << endl;
    }
    else
    {
        cout << "Element not found in BST " << endl;
    }

    cout << endl
         << endl;

    cout << "************Iterative Search in BST ************" << endl;
    // Iterative Approach is used below
    Node *m = Object.search_Iterative(root, 45);
    if (m != NULL)
    {
        cout << "Found :: " << m->data << endl;
        cout << "Element found in BST" << endl;
    }
    else
    {
        cout << "Element not found in BST " << endl;
    }

    return 0;
}

// Searching in a Binary Search Tree :: Best Case Time complexity O(logn) and Worst Case Time complexity O(n)
// O(n) is for Skew tree which is Binary Search Tree and it acted as linked list

// search ----> 55 -----> key (NOTE:: height of Tree is 3 and 3 comparison is possible)
//
//                         50  <--- root        root < key ==> 50 < 55 // go to right subtree
//                       /    |
//                      40     60
//                    /  |    /  |
//                   20  45  55  70

//
//                         50
//                       /   ||
//                      40     60  <--- root        root > key ==> 60 > 55 // go to left subtree
//                    /  |    /  |
//                   20  45  55  70

//
//                         50
//                       /   ||
//                      40     60
//                    /  |   //  |
//                   20  45  55  70
//                            ^
//                            |--- root       root == key ==> 55 == 55 // Element found

//
// search ----> 45 -----> key (NOTE:: height of Tree is 3 and 3 comparison is possible)
//
//                         50  <--- root        root > key ==> 50 > 45 // go to left subtree
//                       /    |
//                      40     60
//                    /  |    /  |
//                   20  45  55  70

//
//                         50
//                       //   |
//                      40     60  <--- root        root < key ==> 40 < 45 // go to right subtree
//                    /  |    /  |
//                   20  45  55  70

//
//                         50
//                       //  |
//                      40     60
//                    /  ||   /  |
//                   20  45  55  70
//                       ^
//                       |--- root       root == key ==> 45 == 45 // Element found

//
