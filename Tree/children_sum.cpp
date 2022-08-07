#include <iostream>
#include <queue>
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

bool childrenSum(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
        sum = sum + root->left->key;
    if (root->right != NULL)
        sum = sum + root->right->key;
    return (root->key == sum && childrenSum(root->left) && childrenSum(root->right));
}

int main()
{ /*
                 root                                     10
                /    \                                  /    \
              left   right                            50      70
             /  \     /  \                          /   \   /   \
            l1 r1    l2   r2                      30    80 90   40

  */
    node *root = new node(80);
    node *left = new node(50);
    node *right = new node(30);
    node *left1 = new node(30);
    node *right1 = new node(20);
    node *left2 = new node(20);
    node *right2 = new node(70);
    // node t(0);
    node::assign(root, left, right);
    node::assign(left, left1, right1);
    node::assign(right, left2, right2);

    inorder(root);
    cout << endl;
    cout << "Is Children Sum : " << (childrenSum(root) > 0 ? "True" : "False") << endl;
    return 0;
}