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

node *getSuccessor(node *root)
{
    root = root->right;
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
node *deleteItem(node *root, int node)
{
    // Step 1: searching the position of node in BTree
    if (root == NULL)
        return root;
    if (root->key > node)
        root->left = deleteItem(root->left, node);
    else if (root->key < node)
        root->right = deleteItem(root->right, node);
    // Step 2: after finding position of node , now deleting the node
    else // when root->key ==  node
    {
        if (root->left == NULL) // Case 1
        {
            struct node *tnode = root->right;
            delete root;
            return tnode; // deleting the root and returning the right of root as root
        }
        else if (root->right == NULL) // Case 2
        {
            struct node *tnode = root->left;
            delete root;
            return tnode; // deleting the root and returning the left of root as root
        }
        else // Case 3
        {
            struct node *succ = getSuccessor(root);           // finding successor of the root node
            root->key = succ->key;                            // replacing value of root with value of successor (i.e placing successor in position of root)
            root->right = deleteItem(root->right, succ->key); // now re calling the deleteItem() for right sub tree, to delete the successor key from subtree
        }
    }
    return root;
}

int main()
{
    /*             Balanced
                      50                                        90 (case 3)
                    /    \                                    /    \
                  30      80                       (case 2) 20     40 (case 1)
                /   \   /   \                             /   \   /   \
              20    40 70   90                          30  NULL NULL  60

        3 Cases for deleting root from BTree        (root can be any node)

        1.  root        when root->left = NULL (left child is null)
           /   \        then we delete the root element and return right child in root position
         NULL  50

        2. root         when root->right = NULL (right child is null)
          /   \         then we delete the root element and return the left child in root position
        30    NULL

        3. root         when root->left=root->right!=NULL (both children are non empty)
          /   \         then we delete the root element and return the next order element called successor(bigger than root),(by inorder traversal) in
         60   40        place for root , then we recursively call the fn to delete the successor from btree.

     */

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

    deleteItem(root, 40);
    inorder(root);
    cout << endl;

    return 0;
}