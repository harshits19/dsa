#include <iostream>
using namespace std;
/*
Binary Search Tree is a node-based binary tree data structure which has the following properties:
-The left subtree of a node contains only nodes with keys lesser than or equal to the node's key.
-The right subtree of a node contains only nodes with keys greater than the node's key.
-The left and right subtree each must also be a binary search tree.
-There must be no duplicate nodes.
-can be implimented on maps, sets,  multimap and multisets.

Binary Search Tree Time complexity for various operations
Search,Insert,Delete, Find closest - O(log n)
Sorted Traversal - O(n)
 */

struct node
{
    int key;
    node *left;
    node *right;
    node(int x)
    {
        key = x;
        left = right = NULL;
    }
    static void assign(node *t, node *l = NULL, node *r = NULL)
    {
        t->left = l;
        t->right = r;
    }
};

void inorder(node *root) // default inorder
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    /*      Balanced Binary Tree                         Balanced               Unbalanced(but still Btree)
                 root                                     50                        10
                /    \                                  /    \                       \
              left   right                            30      80                      20
(smaller than root)  (larger than root)             /   \   /   \                      \
                                                  20    40 70   90                      30
  */
    node *root = new node(50);
    node *left = new node(30);
    node *right = new node(80);
    node *left1 = new node(20);
    node *right1 = new node(40);
    node *left2 = new node(70);
    node *right2 = new node(90);
    // node t(0);
    node::assign(root, left, right);
    node::assign(left, left1, right1);
    node::assign(right, left2, right2);

    inorder(root);
    return 0;
}