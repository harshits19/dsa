#include <iostream>
#include <stack>
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

struct MyStack
{
    node *head;
    int siz;
    MyStack()
    {
        head = NULL;
        siz = 0;
    }
    void push(int x)
    {
        node *temp = new node(x); // create a new node
        temp->next = head;        // link it with head
        head = temp;              // update the head to new node
        siz++;
    }
    int pop()
    {
        if (head == NULL)
            return -1;
        int res = head->data;
        node *temp = head;
        head = head->next;
        delete temp;
        siz--;
        return res;
    }
    int peek()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }
    int size()
    {
        return siz;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    void display(node *head)
    {
        node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    MyStack s;
    s.push(20);
    s.push(74);
    s.push(51);
    s.display(s.head);

    return 0;
}