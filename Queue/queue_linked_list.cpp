#include <iostream>
using namespace std;

struct node
{
    node *next;
    int data;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct queue
{
    int size, cap;
    node *front, *rear;
    queue(int x)
    {
        cap = x;
        size = 0;
        front = NULL;
        rear = NULL;
    }
    // All operations perform in time : O(1)
    void enqueue(int data) // in enqueue we have to store item at rear and move it ahead
    {
        node *temp = new node(data);
        if (front == NULL) // for empty queue : important corner case
        {
            front = rear = temp; // base case when list is empty , front and rear points to that single node
            size++;
            return;
        }
        rear->next = temp;
        rear = temp;
        size++;
    }
    void dequeue() // in dequeue we have to deallocate front and move it one position forward
    {
        if (front == NULL) // if front is null then queue is already empty
            return;
        node *temp = front;
        front = front->next;
        if (front == NULL) // if front becomes null after pointing to its next(which means it's the last node of the list) then we have to make rear also null
            rear = NULL;
        delete temp;
        size--;
    }

    int getSize()
    {
        if (front = rear = NULL)
            return -1;
        return size;
    }
    int getFront()
    {
        // if (front = rear = NULL)
        //  return -1;
        return front->data;
    }
    int getRear()
    {
        // if (front = rear = NULL)
        //   return -1;
        return rear->data;
    }
    void display(node *front)
    {
        cout << "Queue: ";
        node *ptr = front;
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
    queue q(5);
    q.enqueue(50);
    q.enqueue(40);
    q.enqueue(20);
    q.enqueue(70);
    q.enqueue(10);
    q.display(q.front);
    // cout << "Size: " << q.getSize() << endl;
    q.dequeue();
    q.dequeue();
    q.display(q.front);
    cout << "Size: " << q.getSize() << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "\nRear: " << q.getRear() << endl;
    return 0;
}