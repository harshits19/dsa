#include <iostream>
using namespace std;

struct node // structure is used to define the custom data type , here we defined a node datatype which contains an integer and pointer(of itself dataype i.e node)
{
    int data;
    node *next;
    node(int x) // default constructor for structure
    {
        data = x;
        next = NULL;
    }
};

void viewlist(node *head) // here head is a local variable //time : O(n) , space : none
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void viewlistrec(node *curr) // time : O(n) space : O(n) recursive fn
{
    if (curr == NULL)
        return;
    else
    {
        cout << curr->data << " ";
        viewlistrec(curr->next);
    }
    cout << endl;
}

node *insertAtBeg(node *head, int dat) // time : O(n)
{
    node *tempnode = new node(dat); // node is a datatype , here a pointer tempnode of datatype node is storing the address of newly created object of datatype node
    tempnode->next = head;
    return tempnode; // we are returning a pointer datatype of node
}
node *insertAtEnd(node *head, int dat)
{
    node *tnode = new node(dat);
    if (head == NULL)
    {
        return tnode;
    }
    else
    {
        node *ptr = head; // this pointer will traverse through the array till last node
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }                   // when this loop terminates the pointer will point to the last node of LL
        ptr->next = tnode;  // linking the list with last node
        tnode->next = NULL; // making the next of last node NULL
        return head;
    }
}

node *deleteFirstNode(node *head)
{
    if (head == NULL)
        return NULL;
    node *tempnode = head->next;
    delete head;
    return tempnode;
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
    node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }                   // after coming out of loop the pointer will sit on second last node, pointing towards last node
    delete (ptr->next); // we delete the next node of current(second last) node i.e. last node
    ptr->next = NULL;   // now,we link the second last node to NULL
    return head;
}

node *insertAtAnyNode(node *head, int pos, int dat)
{
    node *tempnode = new node(dat);
    if (pos == 1) // corner case: if element inserted at first position, then link it to second node, and return it in place of head
    {
        tempnode->next = head;
        return tempnode;
    }
    node *ptr = head;
    for (int i = 1; i <= (pos - 2) && ptr != NULL; i++) // corner case: when position is higher than the size of linked list then (ptr == NULL)
        ptr = ptr->next;
    if (ptr == NULL) // in this condition the ptr becomes null so we simply return head
        return head;
    tempnode->next = ptr->next;
    ptr->next = tempnode;
    return head;
}

int search(node *head, int key)
{
    node *ptr = head;
    int pos = 1;
    while (ptr != NULL)
    {
        if (ptr->data == key)
            return pos;
        else
        {
            pos++;
            ptr = ptr->next;
        }
    }
    return -1;
}

int main()
{
    node *head = new node(20); // declaring head object dynamically using new keyword
    head->next = new node(30);
    head->next->next = new node(40);
    head->next->next->next = new node(50);

    cout << "Initial List: ";
    viewlist(head); // head is passed only for traversing the array

    head = insertAtBeg(head, 10);
    cout << "Insert at Beg : ";
    viewlist(head);

    head = insertAtEnd(head, 60);
    cout << "Insert at End : ";
    viewlist(head);

    head = deleteFirstNode(head);
    cout << "Delete from Beg : ";
    viewlist(head);

    head = deleteLastNode(head);
    cout << "Delete from End : ";
    viewlist(head);

    head = insertAtAnyNode(head, 2, 90);
    cout << "Insert at given Pos : ";
    viewlist(head);

    cout << "90 present at index : " << search(head, 90);
    // viewlist(head);

    return 0;
}