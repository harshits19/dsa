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

node *removeDuplicates(node *head)
{
    if (head == NULL)
        return NULL;
    node *ptr = head;
    while (ptr != NULL && ptr->next != NULL)
    {
        if (ptr->data == ptr->next->data)
        {
            node *temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        }
        else
            ptr = ptr->next;
    }
    return head;
}
int main()
{
    node *head = new node(20);
    node *first = new node(30);
    node *second = new node(30);
    node *third = new node(50);
    node *forth = new node(60);
    node *fifth = new node(60);
    node *sixth = new node(60);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout << "Initial List: ";
    viewlist(head);

    cout << "Removing Duplicates: ";
    head = removeDuplicates(head);
    viewlist(head);

    return 0;
}