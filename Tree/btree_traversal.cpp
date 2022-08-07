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
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;   // create queue to store nodes of tree
    q.push(root);      // push root into queue
    while (!q.empty()) // push children of root & pop root until que is empty
    {
        node *curr = q.front(); // pointer to front of queue (root)
        cout << curr->key << " ";
        q.pop();                // pop root node
        if (curr->left != NULL) // push left child
            q.push(curr->left);
        if (curr->right != NULL) // push right child
            q.push(curr->right);
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

    cout << "Pre Order: ";
    preorder(root);
    cout << endl;
    cout << "In Order: ";
    inorder(root);
    cout << endl;
    cout << "Post Order: ";
    postorder(root);
    cout << endl;
    cout << "Level Order: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}