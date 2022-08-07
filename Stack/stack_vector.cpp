#include <iostream>
#include <vector>
using namespace std;

struct MyStack
{
    vector<int> arr;
    void push(int x)
    {
        arr.push_back(x);
    }
    int pop()
    {
        int res = arr.back();
        arr.pop_back();
        return res;
    }
    int peek()
    {
        return arr.back();
    }
    int size()
    {
        return arr.size();
    }
    int isEmpty()
    {
        return arr.empty();
    }
    void display()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyStack s;  // creating a stack
    s.push(23); // pushing value in stack
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
    cout << "Stack: ";
    s.display();
    return 0;
}