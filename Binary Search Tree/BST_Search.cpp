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
    static void assign(node *t, node *l = NULL, node *r = NULL)
    {
        t->left = l;
        t->right = r;
    }
};

bool searchRec(node *root, int val) // Recursive Search : with Time : O(log h), Space : O(h) where h is height of btree
{
    if (root == NULL)
        return false;
    else if (root->key == val)
        return true;
    else if (root->key < val)
        return searchRec(root->right, val);
    else
        return searchRec(root->left, val);
}

bool searchItr(node *root, int val) // Iterative Search with Time : O(log h), Space : O(1) no auxilary space required
{                                   //
    while (root != NULL)            // run until we reach last node which will be equal to NULL(i.e. right=left=NULL)
    {                               //
        if (root->key == val)       // check if value equal to current key then return true
            return true;            //
        else if (root->key < val)   // if value is more than key, then it should be present on right side of current key
            root = root->right;     //
        else                        // else it should be present on left side of current key
            root = root->left;      //
    }                               //
    return false;                   // if value not found i.e the root reaches NULL value, return false
}

node *searchItem(node *root, int val) // returns the item if present
{
    if (root == NULL || root->key == val)
        return root;
    if (root->key < val)
        return searchItem(root->right, val);
    else
        return searchItem(root->left, val);
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

    cout << "Search 23 Recusively : " << (searchRec(root, 23) > 0 ? "True" : "False") << endl;
    cout << "Search 90 Iteratively : " << (searchItr(root, 70) > 0 ? "True" : "False") << endl;
    node *temp = searchItem(root, 40);
    cout << "Search 40 Present : " << temp->key << endl;
    return 0;
}