#include <iostream>
#include <queue>
using namespace std;

struct myStack
{
    queue<int> a, b;
    int size = 0;

    void push(int x)
    {
        while (!a.empty())
        {
            b.push(a.front());
            a.pop();
        }
        a.push(x);
        while (!b.empty())
        {
            a.push(b.front());
            b.pop();
        }
        size++;
    }

    void pop()
    {
        a.pop();
        size--;
    }
    int stsize()
    {
        if (a.empty())
            return -1;
        return size;
    }
    int top()
    {
        if (a.empty())
            return -1;
        return a.front();
    }

    void display()
    {
        queue<int> ptr = a;
        while (!ptr.empty())
        {
            cout << ptr.front() << " ";
            ptr.pop();
        }
        cout << endl;
    }
    void display2(myStack s)
    {
        while (a.empty() == 0)
        {
            cout << s.top() << " ";
            s.pop();
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
    myStack s;
    s.push(45);
    s.push(65);
    s.push(78);
    s.push(56);
    s.display();
    s.pop();
    s.pop();
    cout << "Size: " << s.stsize() << endl;
    s.display2(s);

    return 0;
}