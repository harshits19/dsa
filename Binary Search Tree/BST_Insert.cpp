#include <iostream>
using namespace std;
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
    /*  static void assign(node *t, node *l = NULL, node *r = NULL)
     {
         t->left = l;
         t->right = r;
     } */
};

node *insertRec(node *root, int val)
{
    if (root == NULL)                              // if tree is empty , then return the newly allocated node as root
        return new node(val);                      // or, when the root reaches the correct position of the item then return the newly assigned node
    else if (root->key < val)                      // if value is greater than current root key then move root to its right child
        root->right = insertRec(root->right, val); // assign the value returned by recursion as right of root
    else if (root->key > val)
        root->left = insertRec(root->left, val);
    return root; // at last after all recusion, the root will travel back to itself, then return the original root element
}

node *insertItr(node *root, int val)
{
    node *temp = new node(val); // allocate the new node for the value
    node *parent = NULL;        // create temp variable parent to link it to the temp item
    node *curr = root;          // for traversing the btree
    while (curr != NULL)        // when current reaches null it means it stands on the correct position of the item
    {
        parent = curr; // assign current node as parent
        if (curr->key < val)
            curr = curr->right;
        else if (curr->key > val)
            curr = curr->left;
        else
            return root; // if the passed value is already present in btree , then return the old root
    }                    // when loop terminates, we get parent position of the value (i.e the node(parent) to which the value(child) will be attached)
    if (parent == NULL)
        return temp;
    else if (parent->key > val) // if parent is greater than value, then the temp node assigned as left child
        parent->left = temp;    //
    else                        // else the temp node assigned as right child
        parent->right = temp;
    return root;
}
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
    /* node *root = new node(50);
    node *left = new node(30);
    node *right = new node(80);
    node *left1 = new node(20);
    node *right1 = new node(40);
    node *left2 = new node(70);
    node *right2 = new node(90);
    node::assign(root, left, right);
    node::assign(left, left1, right1);
    node::assign(right, left2, right2); */

    // Note: In this method , the order of insertion matters for balancing the tree correctly
    node *root = NULL;          // creating an empty tree with null root
    root = insertRec(root, 50); // assigning the new root value
    insertRec(root, 30);
    insertRec(root, 20);
    insertRec(root, 40);
    insertRec(root, 80);
    insertRec(root, 70);
    insertRec(root, 90);

    inorder(root);
    cout << endl;

    insertRec(root, 35);
    cout << root->left->right->left->key << endl; // correct position of 35

    inorder(root);
    cout << endl;

    insertItr(root, 75);
    cout << root->right->left->right->key << endl; // correct position of 75

    inorder(root);
    cout << endl;

    return 0;
}