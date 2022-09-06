#include <iostream>
#include <queue>
using namespace std;

void display(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{ // all operations in time : O(1)
    queue<int> q;
    q.push(23);
    q.push(34);
    q.push(52);
    q.push(83);
    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
    cout << "Size : " << q.size() << endl;
    display(q);
    q.pop();
    q.pop();
    display(q);
    int a = q.front();
    cout << a;
    return 0;
}