#include <iostream>
using namespace std;
/* A Floor is the value which is equal or minimum(smaller) closest to the value given to search in the BST
               Balanced              For eg.
                  50                      -floor(root,65)
                /    \                    65 is not present then floor will be 50 (smallest closest to the searched value)
              30      80                  -floor(root,80)
            /   \   /   \                 80 is present in Btree hence floor will be 80
          20    40 70   90

    A Ciel is the value which is equal or maximum(larger) closest to the value given to search in the BST
        For eg.
        -ciel(root,75)
        75 is not present in BST then ciel would be 80 (largest value close to searched value)


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

node *floorBST(node *root, int val) // iterative approach with time: O(log h) and space: O(1)
{
    node *res = NULL;
    while (root != NULL)
    {
        if (root->key == val)
            return root;
        else if (root->key > val)
            root = root->left;
        else if (root->key < val)
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}

node *cielBST(node *root, int val)
{
    node *res = NULL;
    while (root != NULL)
    {
        if (root->key == val)
            return root;
        else if (root->key < val)
            root = root->right;
        else if (root->key > val)
        {
            res = root;
            root = root->left;
        }
    }
    return res;
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
    node *res = floorBST(root, 69);
    cout << "Nearest Floor value for 69 is : " << res->key << endl;

    node *res2 = cielBST(root, 78);
    cout << "Nearest Ciel value for 78 is : " << res2->key << endl;

    return 0;
}