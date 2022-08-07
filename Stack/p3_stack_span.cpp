#include <iostream>
//#include <iomanip>
#include <stack>
using namespace std;

/* Span:
    Span is the no of values which are on the left side of current element(including current element) that are smaller or equal to the current value
    eg.
        NODES   20  10  50  45  60  25  30  35  55  70  50
        SPAN    1   1   3   1   5   1   2   3   4   9   1
    Note: span of first element is always 1
    EG: suppose span of 60 is               span of 35 is
        +1  (50 itself)                     +1  (35 itself)
        +1  (10<50)                         +1  (30<35)
        +1  (20<50)                         +1  (25<30)
    Span=3                                  STOP(60>35)
                                        Span=3

 */

// Effective method with time : O(n) and implementing the stack
void printSpan(int *arr, int n)
{
    stack<int> s;
    cout << "1  "; // Span of first element is always 1
    s.push(0);     // push index of first element in stack

    for (int i = 1; i < n; i++) // processing further elements
    {
        while (s.empty() == false && arr[s.top()] <= arr[i]) // while stack is non-empty and current element is greater than top element in stack
        {
            s.pop(); // removing all small or equal elements from stack
        }
        int span = (s.empty() ? i + 1 : i - s.top());
        // if stack is empty it means current item is largest hence its span would be (from first to current item) i.e index[current]+1;
        // if stack is non empty then span would be values from largest element to the current element i.e index[current] - stack[top];

        // cout << setw(2) << setfill('0') << span << " ";
        cout << span << "  ";
        s.push(i); // push the index of current element into stack
    }
    cout << endl;
}

// Naive method with time: O(n^2)
void printSpanNaive(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--) // start from (i-1)index towards starting index (i=0) while cur_item[j] < item[i]
        {
            span++; // increase span value
        }
        cout << span << "  ";
    }
    cout << endl;
}

int main()
{
    int span[10] = {20, 40, 35, 50, 55, 60, 25, 30, 65, 45};
    int i = 0;
    for (int i; i < 10; i++)
    {
        cout << span[i] << " ";
    }
    cout << endl;
    printSpan(span, 10);
    printSpanNaive(span, 10);
    return 0;
}