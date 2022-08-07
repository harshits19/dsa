#include <iostream>
using namespace std;

/* The Stack is a linear data structure, which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

Mainly, the following three basic operations are performed in the stack:
Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
Pop: Removes an item from the stack. The items are popped in the reversed order in which they were pushed. If the stack is empty, then it is said to be an Underflow condition.
Peek or Top: Returns the top element of the stack.
isEmpty: Returns true if the stack is empty, else false.

 */

struct MyStack
{
    int *arr; // creating pointer to point the dynamic array
    int cap;  // capacity
    int top;  // position of top pointer (index)
    MyStack(int x)
    {
        cap = x;
        arr = new int[cap]; // creating a dynamic array
        top = -1;
    }
    void push(int x)
    {
        if (top == cap - 1)
            cout << "Stack Overflow, can't push " << x << endl;
        else
        {
            top++;
            arr[top] = x;
        }
    }
    int pop(void)
    {
        if (top == -1)
            cout << "Stack Underflow" << endl;

        int res = arr[top];
        top--;
        return res;
    }
    int peek()
    {
        return arr[top];
    }
    int size()
    {
        return (top + 1);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyStack s(5); // creating a stack of size 5
    s.push(23);   // pushing value in stack
    s.push(45);
    cout << "Stack: ";
    s.display();
    cout << "Size: " << s.size() << endl;
    s.push(56);
    s.push(87);
    s.push(67);
    cout << "Stack: ";
    s.display();
    cout << "Size: " << s.size() << endl;
    cout << "Top Element: " << s.peek() << endl;
    cout << "Empty: " << (s.isEmpty() == 1 ? "true" : "False") << endl;
    s.push(98);
    s.push(90);
    cout << "Stack: ";
    s.display();
    cout << "POP " << s.pop() << endl;
    cout << "POP " << s.pop() << endl;
    cout << "Stack: ";
    s.display();
    cout << "POP " << s.pop() << endl;
    cout << "POP " << s.pop() << endl;
    cout << "POP " << s.pop() << endl;
    s.pop();

    return 0;
}