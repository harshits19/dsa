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

void inorder(node *root) // default inorder
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int heightofBtree(node *root)
{
    if (root == NULL)
        return 0;
    return (max(heightofBtree(root->left), heightofBtree(root->right)) + 1);
}

void printKthNode(node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->key << " ";
    else
    {
        printKthNode(root->left, k - 1);
        printKthNode(root->right, k - 1);
    }
}

int sizeofBtree(node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + sizeofBtree(root->left) + sizeofBtree(root->right)); // 1 is returned by leaf node
}

int maxofBtree(node *root)
{
    if (root == NULL)
        return INT_MIN;
    else
        return max(root->key, max(maxofBtree(root->left), maxofBtree(root->right)));
}
int main()
{ /*
                 root                                     10
                /    \                                  /    \
              left   right                            50      70
             /  \     /  \                          /   \   /   \
            l1 r1    l2   r2                      30    80 90   40

  */
    node *root = new node(10);
    node *left = new node(50);
    node *right = new node(70);
    node *left1 = new node(30);
    node *right1 = new node(80);
    node *left2 = new node(90);
    node *right2 = new node(40);
    // node t(0);
    node::assign(root, left, right);
    node::assign(left, left1, right1);
    node::assign(right, left2, right2);

    inorder(root);
    cout << endl;
    cout << "Height of tree is " << heightofBtree(root) << endl;
    cout << "Nodes at level 2 are ";
    printKthNode(root, 2);
    cout << endl;
    cout << "Size of Btree is " << sizeofBtree(root) << endl;
    cout << "Max node of Btree is " << maxofBtree(root) << endl;
    return 0;
}