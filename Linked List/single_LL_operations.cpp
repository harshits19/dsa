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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Inserting a node in Sorted List
node *sortedInsert(node *head, int data)
{
    node *tnode = new node(data);
    if (head == NULL)
        return tnode;
    if (data < head->data)
    {
        tnode->next = head;
        return tnode;
    }
    node *ptr = head;
    while (ptr->next->data < data)
        ptr = ptr->next;
    tnode->next = ptr->next;
    ptr->next = tnode;
    return head;
}

void middleOfLL(node *head)
{
    if (head == NULL)
        return;
    node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    /* Alternate:
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
            count++;
     */
    ptr = head;
    for (int i = 0; i < count / 2; i++)
        ptr = ptr->next;
    cout << ptr->data << endl;
}

// Effective Method
/* In this, we take two pointers slow and fast both pointing to head
slow moves one node ahead at a time, fast moves two nodes ahead at a time
when fast reaches last node or end of list(i.e NULL) the slow moves to the middle element bcoz slow moves half the nodes of fast
odd node case : fast -> last node (i.e fast->next = NULL)
even node case : fast -> NULL
 */
void middleOfLLEff(node *head)
{
    if (head == NULL)
        return;
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}

void nthFromEnd(node *head, int n)
{
    if (head == NULL)
        return;
    node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    ptr = head;
    for (int i = 1; i < count - n + 1; i++)
        ptr = ptr->next;
    cout << ptr->data << endl;
}

int main()
{
    node *head = new node(20);
    node *first = new node(30);
    node *second = new node(40);
    node *third = new node(50);
    node *forth = new node(60);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;

    cout << "Initial List: ";
    viewlist(head);

    cout << "Inserting 35: ";
    head = sortedInsert(head, 35);
    viewlist(head);

    cout << "Middle Node of LL: ";
    // middleOfLL(head);
    middleOfLLEff(head);

    cout << "Nth Node from End (N=4): ";
    nthFromEnd(head, 4);

    return 0;
}