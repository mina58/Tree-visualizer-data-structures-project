//
// Created by Mina on 01-Dec-22.
//

/*
 * This is the header file of the AVLTree class
 * Operations:
 * rotateRight: rotate a node to the right
 * rotateLeft: rotate a node to the left
 * */


#ifndef DATA_STRUCTURES_PROJECT_AVL_H
#define DATA_STRUCTURES_PROJECT_AVL_H

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

typedef int ElementType;

class AVL {

public:
    //AVL node class
    class AVLNode {

    public:
        ElementType data;
        int height;
        AVLNode *left;
        AVLNode *right;

        //default constructor
        AVLNode() : height(0), left(nullptr), right(nullptr), data(0) {};

        //parameterized constructor: takes the value of the node as a parameter
        AVLNode(ElementType val) : height(0), left(nullptr), right(nullptr), data(val) {}

        //this function returns the height of a node. if the node is null then return -1
        static int nodeHeight(AVL::AVLNode *node) {
            if (node == nullptr)
                return -1;
            return node->height;
        }

        //this function updates and returns the height of the node
        int updateHeight() {
            return height = 1 + max(nodeHeight(left), nodeHeight(right));
        }

        //this function calculates and returns the balance factor of a node
        int balanceFactor() const {
            return nodeHeight(left) - nodeHeight(right);
        }

    };//end of AVLNode

    AVLNode *root; //root node

    /***private member functions***/

    //this function performs right rotation on a node
    static AVLNode *rotateRight(AVLNode *node);

    //this function performs left rotation on a node
    static AVLNode *rotateLeft(AVLNode *node);

    //this function check if a node is balanced, if not it balances it
    static AVLNode *balance(AVLNode *node);

    //this is an auxiliary function to insert a value from the perspective of the nodes
    AVLNode *insertAux(ElementType val, AVLNode *&node);

    //this is an auxiliary function to remove a value from the perspective of the nodes
    AVLNode *removeAux(ElementType val, AVLNode *&node);

    //this function returns a pointer to the node with the minimum value of a subtree and returns nullptr
    // if the node is null
    AVLNode *minNode(AVLNode *node);

    //this is an auxiliary function that fills a vector with the inorder traversal from the node perspective
    void inorderAux(vector<ElementType> &v, AVLNode *node);

    //this is an auxiliary function to search the tree from the perspective of the nodes
    bool searchAux(ElementType val, AVLNode *node);

    void clearAux(AVLNode *&root);

    /***public member functions***/
public:
    //default constructor
    AVL();

    //this function inserts a node in the tree
    void insert(ElementType value);

    //this function checks if the tree is empty
    bool empty();

    //this function removes a value from the tree
    void remove(ElementType val);

    //this function takes a vector and fills it with the inorder traversal of the tree
    void inorderTraversal(vector<ElementType> &v);

    //this function clears the tree
    void clear();

    //this function checks if the given value is in the tree
    bool search(ElementType val);

    //this function prints the tree in level order
    void levelOrderPrint();

    //destructor
    ~AVL();
    friend class screenAVL;
    friend class Widget;

};
//end of AVL header



#endif //DATA_STRUCTURES_PROJECT_AVL_H
