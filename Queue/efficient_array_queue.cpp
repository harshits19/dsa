#include <iostream>
using namespace std;

// Efficient Queue using front and back
// Implementing the circular array using % operator
/*
        Circular Array :
             0   1  2  3  4  5  6  7
            [20|10|  |  |  |50|60|30]
                ^           ^
               rear       front
            rear = (front+size-1)%cap;
            eg: rear = (5+5-1)%8 = 1
 */
struct queue
{
    int *arr;
    int front, cap, size;

    queue(int x)
    {
        cap = x;
        size = 0;
        front = 0;
        arr = new int[cap];
    }
    bool isFull() { return (size == cap); }
    bool isEmpty() { return (size == 0); }
    void enque(int x)
    {
        if (isFull())
            return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
        cout << "+" << x << endl;
    }
    void deque()
    {
        if (isEmpty())
            return;
        cout << "-" << arr[front] << endl;
        front = (front + 1) % cap;
        size--;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return front;
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        return ((front + size - 1) % cap);
    }
    void showqueue()
    {
        cout << "Queue: ";
        for (int i = front; i <= getRear(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class MyStack
{
private:
    queue<int> into, out;
    int front;

public:
    MyStack() {}

    void push(int x)
    {
        into.push(x);
        front = x;
    }

    int pop()
    {
        queue<int> temp;
        int current;

        while (into.size() != 1)
        {
            front = into.front();
            into.pop();
            out.push(front);
        }

        current = into.front();
        into.pop();

        into = out;
        out = temp;

        return current;
    }

    int top()
    {
        return front;
    }

    bool empty()
    {
        return into.empty();
    }
};

int main()
{
    queue q(10);
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