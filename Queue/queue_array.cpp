#include <iostream>
using namespace std;

/* Queues :
Queue is also a linear data structure that follows a particular order in which the operations are performed. The order is First In First Out (FIFO),
A good example of queue is any queue of consumers for a resource where the consumer who came first is served first.

The difference between stacks and queues is in removing. In a stack, we remove the most recently added item; whereas, in a queue, we remove the least recently added item.

Operations on Queue:
Enqueue: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition.
Dequeue: Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition.
Front: Get the front item from queue.
Rear: Get the last item from queue. */

struct queue
{
    int *arr;
    int cap, size; // cap= capacity of array, size=space occupied in array
    queue(int x)
    {
        cap = x;
        size = 0;
        arr = new int[cap];
    }
    bool isFull() { return (size == cap); }
    bool isEmpty() { return (size == 0); }
    void enque(int x)
    {
        if (isFull())
            return;
        arr[size] = x;
        size++;
        cout << "+" << x << endl;
    }
    void deque()
    {
        if (isEmpty())
            return;
        cout << "-" << arr[0] << endl;
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return 0;
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        return (size - 1);
    }
    void showqueue()
    {
        cout << "Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    queue q(5);
    q.enque(30);
    q.enque(40);
    q.enque(50);
    q.enque(60);
    q.enque(70);
    q.enque(80);
    q.showqueue();
    q.deque();
    q.deque();
    q.deque();
    q.showqueue();
    return 0;
}