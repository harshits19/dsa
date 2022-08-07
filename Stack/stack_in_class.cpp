#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
class MyStack
{
    int siz = 0;

public:
    node *head;
    MyStack() { head = NULL; }

    void push(int);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    void display(node *head);
};
void MyStack::push(int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
    siz++;
    cout << "Push: " << temp->data << endl;
}
int MyStack::pop()
{
    if (head == NULL)
        return -1;
    int res = head->data;
    node *temp = head;
    head = head->next;
    delete temp;
    siz--;
    cout << "Pop: " << res << endl;
    return res;
}
int MyStack::size() { return siz; }
int MyStack::peek() { return head->data; }
bool MyStack::isEmpty() { return (head == NULL); }
void MyStack::display(node *head)
{
    if (head == NULL)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    node *ptr = head;
    cout << "Stack: ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    MyStack s;
    s.push(23);
    s.push(34);
    s.push(45);
    s.display(s.head);
    cout << "Size: " << s.size() << endl;
    cout << "Top: " << s.peek() << endl;
    s.pop();
    s.pop();
    s.display(s.head);
    cout << "Size: " << s.size() << endl;
    return 0;
}