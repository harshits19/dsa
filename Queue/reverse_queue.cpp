#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse(queue<int> &que) // passing the refrence to the address because we have to make actual changes in queue
{
    stack<int> s;
    while (!que.empty())
    {
        s.push(que.front());
        que.pop();
    }
    while (!s.empty())
    {
        que.push(s.top());
        s.pop();
    }
}
void display(queue<int> que)
{
    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q1;
    q1.push(23);
    q1.push(45);
    q1.push(57);
    q1.push(78);
    q1.push(92);
    display(q1);
    reverse(q1);
    display(q1);

    return 0;
}