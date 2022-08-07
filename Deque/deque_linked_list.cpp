#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    static node *getnode(int dat) // static fn is used because it is called inside the deque structure without creating object of structure node
    {
        node *tnode = new node;
        tnode->data = dat;
        tnode->next = tnode->prev = NULL;
        return tnode;
    }
};

class deque
{
public:
    int cap;
    node *front;
    node *rear;
    int size = 0;
    deque(int capty)
    {
        cap = capty;
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }
    void insertFront(int data)
    {
        node *temp = node::getnode(data);
        if (temp == NULL)
            cout << "OverFlow\n";
        if (front == NULL)
            front = rear = temp;
        else
        {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        size++;
    }
    void deleteFront()
    {
        if (front == NULL)
            return;
        node *temp = front;
        front = front->next;
        front->prev = NULL;
        delete temp;
        size--;
    }

    void insertRear(int data)
    {
        node *temp = node::getnode(data);
        if (rear == NULL)
            front = rear = temp;
        else
        {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        size++;
    }
    void deleteRear()
    {
        if (rear == NULL)
            return;
        node *temp = rear;
        rear = rear->prev;
        if (rear == NULL) // this condition occurs when there is only single node in deque
            rear = front = NULL;
        rear->next = NULL;
        delete temp;
        size--;
    }
    int getSize()
    {
        if (isEmpty())
            return -1;
        return size;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return front->data;
    }
    int getRear()
    {
        return rear->data;
    }
    void Erase()
    {
        rear = NULL;
        while (front != NULL)
        {
            node *temp = front;
            front = front->next;
            delete temp;
        }
        size = 0;
    }
    void display(deque q1)
    {
        node *ptr = q1.front;
        cout << "deque: ";
        for (int i = 0; i < getSize(); i++)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    deque q1(9);
    q1.insertFront(45); //[45]
    q1.insertFront(95); //[95|45]
    q1.insertFront(85); //[85|95|45]
    q1.display(q1);
    q1.deleteFront(); //[95|45]
    q1.deleteFront(); //[45]
    q1.display(q1);
    q1.insertRear(55); //[45|55]
    q1.insertRear(67); //[45|55|67]
    q1.insertRear(23); //[45|55|67|23]
    q1.display(q1);
    q1.deleteRear(); //[45|55|67]
    q1.deleteRear(); //[45|55]
    q1.display(q1);
    cout << "Front: " << q1.getFront() << endl;
    cout << "Rear:  " << q1.getRear() << endl;
    q1.Erase();
    q1.display(q1);

    return 0;
}