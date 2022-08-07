#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
    }
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void showList();
    void insertNode(int);
    void deleteNode(int);
};

void LinkedList::insertNode(int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void LinkedList::showList()
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::deleteNode(int nodeOffset)
{
    node *temp1 = head, *temp2 = NULL;
    int ListLen = 0; // length of list

    if (head == NULL)
    {
        cout << "List empty." << endl;
        return;
    }
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be deleted is less than the lengt hof the linked list.
    if (nodeOffset > ListLen)
    {
        cout << "Index out of range" << endl;
        return;
    }

    temp1 = head;
    if (nodeOffset == 1)
    {
        head = head->next;
        delete temp1;
        return;
    }
    // Traverse the list to find the node to be deleted.
    while (nodeOffset-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next; // Change the next pointer of the previous node.
    delete temp1;
}

int main()
{
    LinkedList list;

    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    cout << "Elements of the list are: ";
    list.showList();
    cout << endl;

    list.deleteNode(2);
    cout << "Elements of the list are: ";
    list.showList();
    cout << endl;
    return 0;
}