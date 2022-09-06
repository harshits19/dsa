#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
vector<int> topView(Node *root) {
    vector<int> ans;
    if (!root)
        return ans;
    map<int, int> treeNodes;    // hd, root->data
    queue<pair<Node *, int>> q; // node , hd

    q.push({root, 0}); // pushing root node whose hd = 0
    while (!q.empty()) {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first; // the first item in pair stores the node
        int hd = temp.second;         // as second stores the horizontal distance for corresponding node

        if (treeNodes.find(hd) == treeNodes.end()) // if there's no value present at correspoding hd then push the current value of node
            treeNodes[hd] = frontNode->data;

        if (frontNode->left)
            q.push({frontNode->left, hd - 1}); // pushing left node whose hd = hd - 1
        if (frontNode->right)
            q.push({frontNode->right, hd + 1}); // pushing right node whose hd = hd + 1
    }
    for (auto a : treeNodes)
        ans.push_back(a.second);
    return ans;
}
void inorder(Node *root) // default inorder
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // inorder(root);
    vector<int> ans = topView(root);
    for (auto a : ans)
        cout << a << " ";
    return 0;
}
/*
    horizontal distance (hd)
    <-2>----<-1>----<0>----<1>----<2>

                   (1)<0>                  LEVEL 0
                 /      \
                /        \
         <-1>(2)          (3)<1>            LEVEL 1
           /   \         /   \
          /     \       /     \
   <-2>(4)   <0>(5)  (6)<0>   (7)<2>        LEVEL 2
   Top view : 4 2 1 3 7

   hd   -> node
   -2   -> 9
   -1   -> 3
    0   -> 7 , 4, 8 (discard, the values other than 1st, becoz they are just below the top node,hence cannot be seen in top view)
    1   -> 5
    2   -> 6
    implement in - map <hd,root.data>
    make a queue<node,hd>
*/