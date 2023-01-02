//
// Created by Mina on 01-Dec-22.
//
#include "AVL.h"
#include <iostream>
#include <queue>

using namespace std;

AVL::AVL() : root(nullptr) {};

void AVL::insert(ElementType value) {
    if (empty())
        root = new AVLNode(value);
    else
        root = insertAux(value, root); //insert node in the tree and point the root to the new return subtree
}

void AVL::remove(ElementType val) {
    if (empty()) {
        cerr << "Cannot delete, the tree is empty.";
        return;
    } else {
        removeAux(val, root);
    }
}

bool AVL::search(ElementType val) {
    return searchAux(val, root);
}

bool AVL::empty() {
    return (root == nullptr);
}

void AVL::clear() {
    clearAux(root);
    root = nullptr;
}

void AVL::clearAux(AVL::AVLNode *&root) {
    if (root == nullptr)
        return;
    if (root->left)
        clearAux(root->left);
    if (root->right)
        clearAux(root->right);
    delete root;
    root = nullptr;
}

void AVL::inorderTraversal(vector<ElementType> &v) {
    inorderAux(v, root);
}

void AVL::levelOrderPrint() {
    if (empty()) {
        cout << "empty tree";
        return;
    }
    queue<AVLNode *> q;
    AVLNode *cur = root;
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

AVL::~AVL() {
    clear();
}

AVL::AVLNode *AVL::rotateRight(AVL::AVLNode *node) {
    assert(node != nullptr);
    assert(node->left != nullptr);

    AVLNode *p = node->left;
    node->left = p->right;
    p->right = node;
    node->updateHeight();
    p->updateHeight();
    return p;

}

AVL::AVLNode *AVL::rotateLeft(AVL::AVLNode *node) {
    assert(node != nullptr);
    assert(node->right != nullptr);

    AVLNode *p = node->right;
    node->right = p->left;
    p->left = node;
    node->updateHeight();
    p->updateHeight();
    return p;
}

AVL::AVLNode *AVL::balance(AVL::AVLNode *node) {
    if (node->balanceFactor() == 2) { //this is either a left left or left right imbalance
        if (node->left->balanceFactor() == -1) //this is a left right imbalance
            node->left = rotateLeft(node->left); // this will turn it to a left left imbalance
        node = rotateRight(node); //this will fix the left left imbalance
    } else if (node->balanceFactor() == -2) { //this is either a right right or right left imbalance
        if (node->right->balanceFactor() == 1) //this is a right left imbalance
            node->right = rotateRight(node->right); //this will turn it to a right right imbalance
        node = rotateLeft(node); // this will fix the right right imbalance
    }
    return node;
}

AVL::AVLNode *AVL::insertAux(ElementType val, AVL::AVLNode *&node) {
    if (val > node->data) {
        if (node->right != nullptr)
            node->right = insertAux(val, node->right); //insert the node in the right subtree and return the new root
        else
            node->right = new AVLNode(val); //just create a new node on the right
    } else if (val < node->data) {
        if (node->left != nullptr)
            node->left = insertAux(val, node->left); //insert the node in the left subtree and return the new root
        else
            node->left = new AVLNode(val); //just create a new node on the left
    }
    node->updateHeight(); //update the height of the node after the insertion
    return balance(node); //balance the tree from bottom to up and return the balanced node
}

AVL::AVLNode *AVL::removeAux(ElementType val, AVL::AVLNode *&node) {
    if (node == nullptr) {
        cerr << "Cannot delete, " << val << " was not found.";
        return nullptr;
    }

    if (val < node->data)
        node->left = removeAux(val, node->left); //delete the node from the left subtree and return the new node
    else if (val > node->data)
        node->right = removeAux(val, node->right); //delete the node from the right subtree and return the new node
    else {
        AVLNode *temp = node; //this temp will hold the node to be deleted while the node pointer
        // will hold the return value

        if (node->left == nullptr && node->right == nullptr) //case 1: no children
            node = nullptr;
        else if (node->left == nullptr) //case 2: 1 child (left)
            node = node->right;
        else if (node->right == nullptr) //case 2: 1 child (right)
            node = node->left;
        else { //case 3: 2 children
            AVLNode *successor = minNode(node->right); //get the successor
            node->data = successor->data; //get the value in the successor
            node->right = removeAux(node->data, node->right); //delete the successor in the right subtree
            temp = nullptr; //if we do not change the value of the temp, it will be deleted at the end of the function,
            //and we already deleted the successor
        }

        if (temp != nullptr)
            delete temp; // delete the node
    }

    if (node != nullptr) {
        node->updateHeight(); //update the height of the node after the deletion
        node = balance(node); //balance the tree from bottom to up
    }
    return node;
}

AVL::AVLNode *AVL::minNode(AVL::AVLNode *node) {
    AVLNode *cur = node;
    while (cur != nullptr && cur->left != nullptr)
        cur = cur->left;
    return cur;
}

void AVL::inorderAux(vector<ElementType> &v, AVLNode *node) {
    if (node != nullptr) {
        if (node->left != nullptr)
            inorderAux(v, node->left);
        v.push_back(node->data);
        if (node->right != nullptr)
            inorderAux(v, node->right);
    }
}

bool AVL::searchAux(ElementType val, AVL::AVLNode *node) {
    if (node == nullptr)
        return false;
    if (val > node->data)
        return searchAux(val, node->right);
    else if (val < node->data)
        return searchAux(val, node->left);
    else
        return true;
}
