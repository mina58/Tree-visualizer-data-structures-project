#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;
/*
Basic Class Methods:
Constructor:Constructs empty BinarySearchTree
empty:returns bool to check if tree is empty
search: given an item the search method will search for the existence of such item in the tree
insert: Insert an item in the BinarySearchTree
remove:Removes an item from the tree
InOrder:Traverses the tree with order Left-Root-Right
Private Methods which contains the root node in:
searchAux: has the root f the tree in its arguments and search for item
InOrderAux: has the root f the tree in its arguments traverses the tree with order Left-Root-Right
levelOrderPrint: prints the tree's nodes level by level
 */
typedef int DataType;

class BST {
public:

    BST();

    ~BST();

    bool empty() const;

    bool search(const DataType &item) const;

    void insert(const DataType &item);

    void remove(const DataType &item);

    void InOrder(vector<DataType> &v);

    void clear();

    void PreOrder();

    void PostOrder();

    void levelOrderPrint();

public:
    class BSTNode {
    public:
        DataType data;
        BSTNode *left;
        BSTNode *right;

        BSTNode() : left(nullptr), right(nullptr) {}

        BSTNode(DataType item) : data(item), left(nullptr), right(nullptr) {}
    };

    typedef BSTNode *NodePointer;
    NodePointer root;

    bool searchAux(BST::NodePointer subtree, const DataType &item) const;

    void insertAux(BST::NodePointer &subtree, const DataType &item);

    void search2(const DataType &item, bool &found, BST::NodePointer &locptr, BST::NodePointer &parent) const;

    void InOrderAux(BST::NodePointer root, vector<DataType> &v);

    void PostOrderAux(BST::NodePointer root);

    void PreOrderAux(BST::NodePointer root);

    void clearAux(NodePointer &root);
    friend class screenBST;
};


#endif // BST_H_INCLUDED
