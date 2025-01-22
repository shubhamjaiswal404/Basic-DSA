#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

class AVL_Tree {
public:
    void preOrderTraversal(Node *root);
    void inOrderTraversal(Node *root);
    int getHeight(Node *n);
    int getBalanceFactor(Node *n);
    int max(int a, int b);
    Node *createNode(int key);
    Node *leftRotate(Node *y);
    Node *rightRotate(Node *x);
    Node *insert(Node *node, int key);
};

int AVL_Tree::getHeight(Node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

Node *AVL_Tree::createNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int AVL_Tree::getBalanceFactor(Node *n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node *AVL_Tree::leftRotate(Node *y) {
    Node *x = y->right;
    Node *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *AVL_Tree::rightRotate(Node *x) {
    Node *y = x->left;
    Node *T2 = y->right;

    y->right = x;
    x->left = T2;

    // 

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

int AVL_Tree::max(int a, int b) {
    return (a > b) ? a : b;
}

Node *AVL_Tree::insert(Node *node, int key) {
    if (node == NULL) {
        return (createNode(key));
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = getBalanceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right Right Case
    if (bf < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right Case
    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVL_Tree::preOrderTraversal(Node *root) {
    if (root != NULL) {
        cout << root->key << "  ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void AVL_Tree::inOrderTraversal(Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << root->key << "  ";
        inOrderTraversal(root->right);
    }
}

int main() {
    AVL_Tree Object;
    Node *root = NULL;
    cout<<"************************Insertion in AVL Tree************************"<<endl;

    //           30 
    //         /   \ 
    //       20     40 
    //      /  \      \ 
    //    10   25     50 
    //        AVL Tree

    root = Object.insert(root, 10);
    root = Object.insert(root, 20);
    root = Object.insert(root, 30);
    root = Object.insert(root, 40);
    root = Object.insert(root, 50);
    root = Object.insert(root, 25);
    cout<<"PreOrder Traversal Of AVL Tree "<<endl;
    Object.preOrderTraversal(root);
    cout<<endl<<"InOrder Traversal Of AVL Tree "<<endl;
    Object.inOrderTraversal(root);
    return 0;
}
// 
// What is AVL Tree? 
//1. It convert Skew Tree into Balance BST 
//2. Height difference between height of left and right subtree for every node is less than or equal to 1
//3. can be -1, 0 or for a node to be balanced in a Binary search tree and can be -1, 0 or for all node of a AVL tree
// 
// Balance Factor  (BF) = Height of right subtree - Height of left subtree 
// 
// | BF | <= 1  ---> -1,0,1
// 
//AVL TREE::::
//                         (J)
//                         +1   <------ BF
//                       /    |             
//                     (F)     (P)
//                     -1      +1               ===> Balance Binary Search Tree
//                    /  |    /  |   
//                 (D)   (G) (L) (V)
//                 -1     0  -1   -1 
//                 /         |   /   |
//               (C)        (N) (S) (X)
//                0          0   0   0 
//                             / |
//                           (Q) (U)
//                            0   0 

// After insertion of a Node 
//
//                         (J)
//                         +1   <------ BF
//                       /    |             
//                     (F)     (P)
//                    -2*      +1
//                    /  |    /  |   
//                 (D)   (G) (L) (V)            ===> Not Balance Binary Search Tree
//                -2*     0  -1   -1            ===> We have to balance by Rotation 
//                 /         |   /   |
//               (C)        (N) (S) (X)
//               -1          0   0   0 
//              /              / |
//inserted--->(Z)            (Q) (U)
//Node         0               0   0 
// 
//****************LL rotation in an AVL Tree**************
//      (7)
//      +1      ==> Tree , its an AVL tree
//      /
//    (5)
//     0

// insert (4) in tree 
// 
//      (7)
//      -2       LL rotation              (5)
//      /                                 +0
//    (5*)       ============>           /  |
//    -1                                (4) (7)
//    /                                  0   0
//  (4)                                   BST
//   0


//****************RR rotation in an AVL Tree****************
//      (7)
//      +1      ==> Tree , its an AVL tree
//        |
//       (9)
//        0

// insert (11) in tree 
// 
//      (7)
//      +2         RR rotation               (9)
//        |                                  +0
//       (9*)       ============>           /  |
//       +1                                (7) (11)
//          |                               0   0
//         (11)                              BST
//          0


//****************LR rotation in an AVL Tree****************
//      (7)
//      +1      ==> Tree , its an AVL tree
//      /
//    (4)
//     0

// insert (5) in tree 
// 
//      (7)                            (7)
//      +2       RR rotation           -2         LL rotation        (5)
//      /                              /                             +0
//    (4*)       ============>        (5*)         ============>    /  |
//    +1                            -1                            (4) (7)
//      |                           /                              0   0
//      (5*)                       (4*)                              BST
//       0                         0

//****************RL rotation in an AVL Tree****************
//      (7)
//      +1      ==> Tree , its an AVL tree
//        |
//       (11)
//        0

// insert (10) in tree 
// 
//       (7)                           (7)
//       +2           LL rotation      +2        RR rotation         (10)
//        |                              |                            +0
//       (11*)       ============>      (10*)     ============>      /  |
//       +1                              +1                        (7) (11)
//      /                                 |                         0   0
//    (10*)                               (11*)                       BST
//     0                                   0
//
// ***********************Rotation in AVL Tree with Multiple Node***********************
//    
// 1. Left - Rotate wrt a Node - Node is moved toward the left {NOTE:: Pully in Law Of Motion , 15 is pulled like pully}
// 
//      9                              (15)                          (15)
//     / |      left rotate            /  |    left rotate           /  | 
//    8  (15)     ========>           9   20    =========>          9   20 
//       /  |    <========           /          <========         / |
//     11*  20   right rotate       8          right rotate      8  11*

//{ 11 is left (leaved) by 15 }
//{11 is 15 se bada chota ===> chota } 
//{11 is 9 se bada chota  ===> bada  }

// 2. Right - Rotate wrt a Node - Node is moved toward the right {NOTE:: Pully in Law Of Motion , 9 is pulled like pully}
//      15                             (9)                             (9)                                                    
//     /  |      right rotate          /  |      right rotate         /  |  
//   (9)   20     ========>          8   15     =========>           8   15  
//   / |         <========                 |    <========              /  | 
//  8  11*       left rotate                20    left rotate        11  20 


//{ 11 is left (leaved) by 9 }
//{11 is 9 se bada chota  ===> bada  }
//{11 is 15 se bada chota ===> chota } 
// 
// Balancing a AVL tree after insertion ::

// Inorder to balance an AVL tree after insertion , we can follow the following rules      |----> {Similar}
// 1)--->For a Left - Left Insertion - Right rotate once wrt the First imbalanced node  ---|
// 2)--->For a Right - Right Insertion - Left rotate once wrt the First imbalanced node ---|
//                                                                                                                    |--->{Similar}
// 3)--->For a Left - Right Insertion - Left rotate once and then Right rotate once wrt the First imbalanced node  ---|
// 4)--->For a Right - left Insertion - Right rotate once and then Left rotate once wrt the First imbalanced node  ---|
//

// For a Left - Left insertion - Right rotate once wrt the first imbalance node
// 
//***********Left - Left insertion*********** 
//Balanced before insertion of 4  
//           11                                                     
//          /  |     
//        (9)   18    
//        / |       
//       5  10*  
// 
//Not Balanced After insertion of 4 {find imbalanced node ---> 11 is imbalanced after insertion of 4 }
//           11                             (9)                             (9)                                                    
//          /  |       right rotate         /  |       right rotate        /  |  
//        (9)  18     ========>           5   11     =========>           5   11  
//        / |                            /      |                        /  /  | 
//       5  10*                         4        18                    4   10*  18 
//      /
//     4
// 
//***********Right - Left insertion*********** 
//Balanced before insertion of 16  
//             (7)                                                
//            /  |   
//           1    10  
//                 |   
//                 17 
//Not Balanced After insertion of 16 {find imbalanced node are ---> 10 and 7 , are imbalanced after insertion of 16 ,(NOTE:: always not go for root first ,start with other node first) }  
//
//  
//              7                               7                            7    
//            /  |     right rotation         /  |      left rotation      /  |   
//           1    10    wrt to 17            1   10^     wrt to 10        1    16  
//                 |   =========>                  |    =========>           /  |    
//                 17*                             16*                     10^   17
//                /                               /                                
//              16*                              17*                       AVL tree          
//                                                                      (Balanced BST )
