#include <iostream>
#include <stack>
using namespace std;
/*
Doubly Linked list
Advantages
can be traversed in both direction
deletes node in O(1) time
insert/delete at given node
insert/delete from both ends in O(1) time
Disadvantages
extra space for *prev
complex code
 */

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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *insertAtBeg(node *head, int data)
{
    node *newhead = new node(data);
    newhead->next = head;
    if (head != NULL)
    {
        head->prev = newhead;
    }
    return newhead;
}

node *insertAtEnd(node *head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
        return newnode;
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
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
    else
    {
        /*  node *ptr = head->next; Alternate Method
         delete head;
         ptr->prev = NULL;
         return ptr; */
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
}

node *deleteLastNode(node *head)
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
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;   // temp reachese the last node
        temp->prev->next = NULL; // the second last node delinkes itself from last node, so its next becomes null
        delete temp;
        return head;
    }
}

// Reversing a Doubly Linked List
node *revLinkedList(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *ptr = head;
    node *prevnode = NULL;
    while (ptr != NULL)
    {
        prevnode = ptr->prev; // swapping the next link with previous link
        ptr->prev = ptr->next;
        ptr->next = prevnode;
        // now the next and previous pointers of ptr are interchanged
        ptr = ptr->prev; // hence to move forward, we change pointer to prev
    }
    return prevnode->prev;
}

node *reverseUsingStack(node *head)
{
    stack<node *> s;
    if (head == NULL || head->next == NULL)
        return head;
    node *ptr = head;
    while (ptr->next != NULL)
    {
        s.push(ptr);
        ptr = ptr->next;
    }
    head = ptr;
    while (!s.empty())
    {
        ptr->next = s.top();
        ptr = ptr->next;
        s.pop();
    }
    ptr->next = NULL;
    return head;
}

int main()
{
    node *head = new node(32);
    node *first = new node(57);
    node *second = new node(84);
    head->next = first;
    first->next = second;
    second->next = NULL;
    first->prev = head;
    second->prev = first;

    cout << "Initial Doubly LL : ";
    viewlist(head);

    cout << "Insert at Beg : ";
    head = insertAtBeg(head, 25);
    viewlist(head);

    cout << "Insert at End : ";
    head = insertAtEnd(head, 12);
    viewlist(head);

    cout << "Delete Head Node: ";
    head = deleteFirstNode(head);
    viewlist(head);

    cout << "Delete Last Node : ";
    head = deleteLastNode(head);
    viewlist(head);

    cout << "Reversed Doubly LL : ";
    head = revLinkedList(head);
    viewlist(head);

    cout << "Reversed Stack LL : ";
    head = reverseUsingStack(head);
    viewlist(head);

    return 0;
}