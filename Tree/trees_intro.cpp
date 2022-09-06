#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// recursively
node *buildTree(node *root) {
    int data;
    if (root != NULL)
        cout << "Enter root data : " << endl;
    cin >> data;
    root = new node(data);
    if (data == -1) {
        return NULL;
    }
    cout << "Enter left child data : " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right child data : " << root->data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

// building a tree in level order form
void buildTreeUsingLOT(node *&root) {
    queue<node *> q;
    int data;
    cout << "Enter root data: " << endl;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty()) {
        node *temp = q.front(); // selecting the root node to enter its left and right child
        q.pop();
        cout << "Enter left child of: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right child of: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {
    node *root;
    // root = buildTree(root);
    //  3 2 9 -1 -1 4 -1 -1 5 7 -1 -1 -1
    buildTreeUsingLOT(root);
    levelOrderTraversal(root);
    return 0;
}
/*eg
         3
       /  \
      2    5
     / \  /
    9  4  7
 Level order traversal (bredth first search): 3,2,5,9,4,7

 */