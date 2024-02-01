//
// Created by Shaswata on 28-Jan-2024.
//

#ifndef DSA_BINARYTREE_H
#define DSA_BINARYTREE_H

class TreeNode{
public:
    TreeNode* left;
    int data;
    TreeNode* right;
};

class BinarySearchTree {
private:
    TreeNode* root;
public:
    BinarySearchTree();
    TreeNode* getRoot();
    void insert(int x);
    TreeNode* recursiveInsert(int x, TreeNode* node);
    void inOrderTraversal(TreeNode* node);
    TreeNode* search(int x);
    static void run();
};


#endif //DSA_BINARYTREE_H
