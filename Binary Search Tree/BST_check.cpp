#include <iostream>
using namespace std;
// Check whether given tree is BST or not
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
};

node *insertItr(node *root, int val)
{
    node *temp = new node(val);
    node *parent = NULL;
    node *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key < val)
            curr = curr->right;
        else if (curr->key > val)
            curr = curr->left;
        else
            return root;
    }
    if (parent == NULL)
        return temp;
    else if (parent->key > val)
        parent->left = temp;
    else
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

bool checkBST(node *root, int min, int max)
{
    if (root == NULL)
        return true;
    else
        return ((root->key > min) &&
                (root->key < max) &&
                checkBST(root->left, min, root->key) &&
                checkBST(root->right, root->key, max));
}

int main()
{
    node *root = NULL;          // creating an empty tree with null root
    root = insertItr(root, 50); // assigning the new root value
    insertItr(root, 30);
    insertItr(root, 20);
    insertItr(root, 40);
    insertItr(root, 80);
    insertItr(root, 70);
    insertItr(root, 90);

    inorder(root);
    cout << endl;

    cout << (checkBST(root, INT_MIN, INT_MAX) > 0 ? "True" : "False") << endl;

    return 0;
}