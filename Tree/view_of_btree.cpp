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
int cur_lvl = 0;
void printLeftView(node *root, int max_lvl)
{
    if (root == NULL)
        return;
    if (cur_lvl < max_lvl)
    {
        cout << root->key << " ";
        cur_lvl = max_lvl;
    }
    printLeftView(root->left, max_lvl + 1);
    printLeftView(root->right, max_lvl + 1);
}

int cur_lvl2 = 0;
void printRightView(node *root, int max_lvl)
{
    if (root == NULL)
        return;
    if (cur_lvl2 < max_lvl)
    {
        cout << root->key << " ";
        cur_lvl2 = max_lvl;
    }
    printRightView(root->right, max_lvl + 1);
    printRightView(root->left, max_lvl + 1);
}

void printLeft(node *root) // Iterative Function for printing left view (similar to level order traversal)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *ptr = q.front();
            q.pop();
            if (i == 0)
                cout << ptr->key << " ";
            if (ptr->left != NULL)
                q.push(ptr->left);
            if (ptr->right != NULL)
                q.push(ptr->right);
        }
    }
}

int main()
{ /*
                 root                                     10
                /    \                                  /    \
              left   right                            50      70
             /  \     /  \                          /   \   /   \
            l1 r1    l2   r2                      30    80 90   40

                10                                      10
                /                                         \
              50                                          70
             /                                              \
           30                                                40
            Left View                           Right View


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

    cout << "Left View: ";
    printLeftView(root, 1);
    cout << endl;
    cout << "Right View: ";
    printRightView(root, 1);
    cout << endl;
    printLeft(root);
    return 0;
}