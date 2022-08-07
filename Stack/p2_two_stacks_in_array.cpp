#include <iostream>
using namespace std;

class twoStacks
{
public:
    int *arr;
    int data, cap, top1, top2;
    twoStacks(int n)
    {
        data = 0;
        cap = n;
        top1 = -1;
        top2 = n;
        arr = new int[n];
    }
    void push1(int);
    void push2(int);
    int pop1();
    int pop2();
    void display1();
    void display2();
};
void twoStacks::push1(int data)
{
    if (top1 < top2 - 1)
    {
        top1++;
        arr[top1] = data;
    }
    else
        exit(1);
}
void twoStacks::push2(int data)
{
    if (top2 > top1 - 1)
    {
        top2--;
        arr[top2] = data;
    }
    else
        exit(1);
}
int twoStacks::pop1()
{
    if (top1 >= 0)
    {
        int res = arr[top1];
        top1--;
        return res;
    }
    else
    {
        cout << "Stack 1 Underflow" << endl;
        return 0;
    }
}
int twoStacks::pop2()
{
    if (top2 < cap)
    {
        int res = arr[top2];
        top2++;
        return res;
    }
    else
    {
        cout << "Stack 2 Underflow" << endl;
        return 0;
    }
}
void twoStacks::display1()
{
    if (top1 >= 0)
    {
        cout << "Stack 1: ";
        for (int i = 0; i <= top1; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack 1 Underflow";
}
void twoStacks::display2()
{
    if (top2 < cap)
    {
        cout << "Stack 2: ";
        for (int i = cap - 1; i >= top2; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack 2 Underflow";
}

int main()
{
    twoStacks t1(20);
    t1.push1(23);
    t1.push1(45);
    t1.push1(78);
    t1.push1(53);
    t1.display1();
    t1.push2(24);
    t1.push2(67);
    t1.push2(93);
    t1.display2();
    t1.pop2();
    t1.pop2();
    t1.pop2();
    t1.pop2();
    t1.pop2();
    t1.push2(67);
    t1.push2(42);
    t1.push2(94);
    t1.push2(39);
    t1.display2();

    return 0;
}