#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void viewlist(node *head)
{
    if (head == NULL)
        return;
    node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}
// naive method with time O(n)
node *insertAtBegNaive(node *head, int data)
{
    node *tnode = new node(data);
    if (head == NULL)
        tnode->next = tnode;
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = tnode;
        tnode->next = head;
    }
    return tnode;
}

// efficient method with time O(1)
node *insertAtBegEff(node *head, int data)
{
    node *tnode = new node(data);
    if (head == NULL)
    {
        tnode->next = tnode;
        return tnode;
    }
    else
    {
        tnode->next = head->next;
        head->next = tnode;
        // swapping values in head(1st) and tnode(2nd)
        int temp = head->data;
        head->data = tnode->data;
        tnode->data = temp;
        return head;
    }
}

// naive method with time O(n)
node *insertAtEndNaive(node *head, int data)
{
    node *tnode = new node(data);
    if (head == NULL)
    {
        tnode->next = tnode;
        return tnode;
    }

    else
    {
        node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = tnode;
        tnode->next = head;
        return head;
    }
}

// efficient method with time O(1)
node *insertAtEndEff(node *head, int data)
{
    node *tnode = new node(data);
    if (head == NULL)
    {
        tnode->next = tnode;
    }

    else
    {
        tnode->next = head->next; // insert tnode after head
        head->next = tnode;
        int temp = head->data; // swap content of head and tnode
        head->data = tnode->data;
        tnode->data = temp;
    }
    return tnode; // return tnode as head
}

node *deleteHeadNaive(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    else
    {
        node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next; // traversing till the last node
        }
        ptr->next =
            head->next;     // link last node to next to head node(i.e. 2nd node)
        delete head;        // delete head node
        return (ptr->next); // return 2nd node as head
    }
}

node *deleteHeadEff(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    else
    {
        head->data = head->next->data; // copy data from 2nd node to head node
        node *temp = head->next;       // assign new temp node for 2nd node
        head->next = head->next->next; // link head to direct 3rd node
        delete temp;                   // delete 2nd node
        return head;                   // return head node which contain value of 2nd node hence
        // it appears that head node is deleted
    }
}

node *deleteKthNode(node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        delete head;
        return NULL;
    }
    node *ptr = head;
    for (int i = 0; i < k - 2; i++)
        ptr = ptr->next;
    node *temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;
    return head;
}

int main()
{
    node *head = new node(23);
    node *first = new node(45);
    node *second = new node(67);
    node *third = new node(83);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = head;

    cout << "Circular LinkedList : ";
    viewlist(head);

    cout << "Insert At Beg : ";
    head = insertAtBegEff(head, 97);
    // head = insertAtBegNaive(head, 97);
    viewlist(head);

    cout << "Insert At End : ";
    head = insertAtEndEff(head, 35);
    // head = insertAtEndNaive(head, 35);
    viewlist(head);

    cout << "Delete Head : ";
    head = deleteHeadEff(head);
    // head = deleteHeadNaive(head);
    viewlist(head);

    cout << "Delete Kth Node (K=2) : ";
    head = deleteKthNode(head, 2);
    viewlist(head);

    return 0;
}