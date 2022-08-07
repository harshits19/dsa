#include <iostream>
using namespace std;

class array
{
public:
    int cap, top;
    int *arr;
    array(int x)
    {
        cap = x;
        arr = new int[cap];
        top = 0;
    }
    void push(int data)
    {
        if (top == 0)
        {
            arr[0] = data;
            top++;
            return;
        }
        if (top == cap)
        {
            cout << "Array Overflow";
            return;
        }
        arr[top] = data;
        top++;
    }
    void pop()
    {
        arr[top] = 0;
        top--;
    }
    void show()
    {
        for (size_t i = 0; i < top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    int size()
    {
        return top;
    }
    void largestElement();
    void smallestElement();
    void secondLargest();
};
void array::largestElement()
{
    if (top == 0)
        return;
    int max = arr[0];
    int maxIdx = 0;
    for (size_t i = 0; i < top; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIdx = i;
        }
    }
    cout << "Max Element: " << max << endl;
    // cout << "Index of Max Element: " << maxIdx << endl;
}
void array::smallestElement()
{
    if (top == 0)
        return;
    int min = arr[0];
    int minIdx = 0;
    for (size_t i = 0; i < top; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIdx = i;
        }
    }
    cout << "Min Element: " << min << endl;
    // cout << "Index of Min Element: " << minIdx << endl;
}
void array::secondLargest()
{
    if (top == 0)
        return;
    int max = 0;
    int secMax = -1;
    for (size_t i = 0; i < top; i++)
    {
        if (arr[i] > max)
        {
            secMax = max;
            max = i;
        }
        else if (arr[i] != arr[max])
        {
            if (secMax == -1 || arr[i] > arr[secMax])
                secMax = i;
        }
    }
    cout << "Second Largest Element: " << arr[secMax] << endl;
}

int main()
{
    array a(10);
    a.push(24);
    a.push(46);
    a.push(53);
    a.push(78);
    a.push(64);
    a.push(15);
    a.show();
    a.largestElement();
    a.smallestElement();
    a.secondLargest();
    return 0;
}