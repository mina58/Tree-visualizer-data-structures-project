#include "BST.h"
#include <iostream>
#include <queue>

using namespace std;

BST::BST():root(nullptr) {}

inline bool BST::empty() const {
    return root == nullptr;
}

bool BST::searchAux(BST::NodePointer subtree, const DataType &item) const {
    if (subtree == nullptr)
        return false; //empty tree

    if (item < subtree->data)
        return searchAux(subtree->left,
                         item);//searches recursively in the left subtree if the item is less than the root
    else if (item > subtree->data)
        return searchAux(subtree->right,
                         item);//searches recursively in the right subtree if the item is greater than the root
    else
        return true;//item is found
}

bool BST::search(const DataType &item) const {
    return searchAux(root, item);
}

void BST::insertAux(BST::NodePointer &subtree, const DataType &item) {
    if (subtree == nullptr)
        subtree = new BST::BSTNode(item);
    else if (item < subtree->data)
        insertAux(subtree->left, item);
    else if (item > subtree->data)
        insertAux(subtree->right, item);
    else
        cerr << "The item is already in the tree \n" << endl;//no duplication
}

void BST::insert(const DataType &item) {
    insertAux(root, item);
}

void BST::search2(const DataType &item,
                  bool &found, BST::NodePointer &locptr,
                  BST::NodePointer &parent) const {
    found = false;
    locptr = root;//locptr is the node i want to delete later
    parent = nullptr;

    while (!found && locptr != nullptr) {
        if (item < locptr->data) {
            parent = locptr;
            locptr = locptr->left;
        } else if (item > locptr->data) {
            parent = locptr;
            locptr = locptr->right;
        } else
            found = true;
    }
}

void BST::remove(const DataType &item) {
    bool found;
    BST::NodePointer x, parent;
    search2(item, found, x, parent);//searches for the item existence in the binary tree
    if (!found) {
        cerr << "The item you want to delete isn't in the tree\n" << endl;
        exit(1);
    }
    // item is in the tree

    if (x->left != 0 && x->right != 0) {//Node has two children
        /*
        In case the node has two children:
        we take the value of our successor and delete the successor
        successor is the leftmost node of our right subtree
        */
        BST::NodePointer xsuccesor = x->right;
        parent = x;

        while (xsuccesor->left !=
               NULL)//the xsuccesor searches to the left of the tree till the left of the tree equals null
        {
            parent = xsuccesor;//at each iteration the parent takes the xsuccesor place and the xsuccesor moves to the left
            xsuccesor = xsuccesor->left;
        }

        x->data = xsuccesor->data;//Move the data of leftmost child of the rightchild of parent to node to be deleted
        x = xsuccesor;//now the x points at the location of the xsuccesor and next we check on the cases of the x which will have only 0 or 1 nodes
    }

    /*after the while loop ends we garantee that the child has only 0 or 1 child
    case node has one or zero child
    */
    BST::NodePointer subtree = x->left;
    if (subtree == 0)//the child is in the right
        subtree = x->right;
    if (parent == 0)//we want to delete the root node
        root = subtree;
    else if (parent->left == x)//the left of the parent is the node i want to delete
        parent->left = subtree;//make the parent's next points at the subtree which is either the right or the left node of the node i want to delete
    else
        parent->right = subtree;

    delete x;
}

void BST::InOrderAux(BST::NodePointer root, vector<DataType> &v) {
//traverses in order of left->root->right
    if (root == nullptr)
        return;

    InOrderAux(root->left, v);
    v.push_back(root->data);
    InOrderAux(root->right, v);
}

void BST::PostOrderAux(BST::NodePointer root) {
    //traverses in order of left->right->node
    if (root == nullptr)
        return;

    PostOrderAux(root->left);
    PostOrderAux(root->right);
    cout << root->data << "\t";
}

void BST::PreOrderAux(BST::NodePointer root) {//traverses the tree in order of root->left->right
    if (root == nullptr)
        return;

    cout << root->data << "\t";
    PreOrderAux(root->left);
    PreOrderAux(root->right);
}

void BST::InOrder(vector<DataType> &v) {
    InOrderAux(root, v);
}

void BST::clearAux(NodePointer &root) {
    if (root == nullptr)
        return;
    if (root->left)
        clearAux(root->left);
    if (root->right)
        clearAux(root->right);
    delete root;
    root = nullptr;
}

void BST::clear() {
    clearAux(root);
}

BST::~BST() {
    clear();
}

void BST::PreOrder() {
    PreOrderAux(root);
}

void BST::PostOrder() {
    PostOrderAux(root);
}

void BST::levelOrderPrint() {
    if (empty()) {
        cout << "empty tree";
        return;
    }
    queue<NodePointer> q;
    NodePointer cur = root;
    q.push(root);
    while (!q.empty()) {
        int size = (int) q.size();
        while (size--) {
            cur = q.front();
            q.pop();
            cout << cur->data << ' ';
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        cout << '\n';
    }
    cout << '\n';
}
