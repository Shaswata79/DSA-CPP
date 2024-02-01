#include <iostream>
#include "BinaryTree.h"


BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

TreeNode *BinarySearchTree::getRoot() {
    return root;
}

void BinarySearchTree::insert(int x) {

    if(root == nullptr){
        root = new TreeNode();
        root->data = x;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }

    TreeNode* current = root;
    TreeNode* previous;

    // traverse until we find empty location
    while(current != nullptr){
        previous = current;
        if(x < current->data){
            current = current->left;
        }else if(x > current->data){
            current = current->right;
        } else{
            return;
        }
    }

    // Now current points at NULL and previous points at insert location
    current = new TreeNode();
    current->data = x;
    current->right = nullptr;
    current->left = nullptr;

    if(x < previous->data){
        previous->left = current;
    } else{
        previous->right = current;
    }

}

TreeNode* BinarySearchTree::recursiveInsert(int x, TreeNode* node) {
    if(node == nullptr){
        node = new TreeNode();
        node->data = x;
        node->right = nullptr;
        node->left = nullptr;
    }else if(x < node->data){
        node->left = recursiveInsert(x, node->left);
    } else if(x > node->data){
        node->right = recursiveInsert(x, node->right);
    }
    return node;
}

void BinarySearchTree::inOrderTraversal(TreeNode* node) {
    if(node != nullptr){
        inOrderTraversal(node->left);
        std::cout << node->data << ", " << std::flush;
        inOrderTraversal(node->right);
    }
}

TreeNode *BinarySearchTree::search(int x) {
    TreeNode* t = root;

    while (t != nullptr){
        if (x == t->data){
            return t;
        } else if (x < t->data){
            t = t->left;
        } else {
            t = t->right;
        }
    }
    return nullptr;
}

void BinarySearchTree::run() {

    BinarySearchTree bst1;

    // Insert
    bst1.insert(10);
    bst1.insert(5);
    bst1.insert(20);
    bst1.insert(8);
    bst1.insert(30);

    // Inorder traversal
    bst1.inOrderTraversal(bst1.getRoot());
    std::cout << std::endl;

    // Search
    TreeNode* temp = bst1.search(20);
    if (temp != nullptr){
        std::cout << temp->data << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    BinarySearchTree bst2;
    // Insert
    bst2.root = bst2.recursiveInsert(10, bst2.getRoot());
    bst2.recursiveInsert(5, bst2.getRoot());
    bst2.recursiveInsert(20, bst2.getRoot());
    bst2.recursiveInsert(8, bst2.getRoot());
    bst2.recursiveInsert(30, bst2.getRoot());
    // Inorder traversal
    bst2.inOrderTraversal(bst2.getRoot());
    std::cout << std::endl;
}


