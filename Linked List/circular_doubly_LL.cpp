#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
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

node *insertAtBeg(node *head, int data)
{
    node *tnode = new node(data);
    if (head == NULL)
    {
        tnode->next = tnode;
        tnode->prev = tnode;
        return tnode;
    }
    tnode->prev = head->prev;
    tnode->next = head;
    head->prev->next = tnode;
    head->prev = tnode;
    return tnode;
}

node *insertAtEnd(node *head, int data)
{
    node *tnode = new node(data);
    if (head == NULL)
    {
        tnode->next = tnode;
        tnode->prev = tnode;
        return tnode;
    }
    tnode->prev = head->prev;
    tnode->next = head;
    head->prev->next = tnode;
    head->prev = tnode;
    return head;
}

node *deleteFirstNode(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *temp = head->next;
    head->data = head->next->data;
    head->next = head->next->next;
    head->next->next->prev = head;
    delete temp;
    return head;
}
node *deleteLastNode(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    node *ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->prev->next = ptr->next;
    head->prev = ptr->prev;
    delete ptr;
    return head;
}

int main()
{
    node *head = new node(24);
    node *first = new node(42);
    node *second = new node(56);
    head->next = first;
    head->prev = second;
    first->next = second;
    first->prev = head;
    second->next = head;
    second->prev = first;

    cout << "Circular Doubly LL : ";
    viewlist(head);

    cout << "Insert At Beg : ";
    head = insertAtBeg(head, 97);
    viewlist(head);

    cout << "Insert At End : ";
    head = insertAtEnd(head, 65);
    viewlist(head);

    cout << "Delete First Node : ";
    head = deleteFirstNode(head);
    viewlist(head);

    cout << "Delete Last Node : ";
    head = deleteLastNode(head);
    viewlist(head);

    return 0;
}