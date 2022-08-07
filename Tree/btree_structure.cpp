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

    return 0;
}