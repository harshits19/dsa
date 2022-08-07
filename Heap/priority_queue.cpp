#include <iostream>
#include <queue>
#include <set>
using namespace std;
/* Priority Queue
    It is a based on Queue and Heap concept
    It works like a max heap, the priority queue arranges itself such that the first(top) element of queue will be always the greatest element
    the elements are sorted in decreasing order in a priority queue
    the top element is popped first from queue.
    It is based on the concepts of heap(due to contagious memory access, cache friendly),but implemented in the vector containers (for dynamic memory allocation)

*/

void display(priority_queue<int> q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
void display(priority_queue<int, vector<int>, greater<int>> q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
void display(priority_queue<set<int>> q)
{
    while (!q.empty())
    {
        cout << "[ ";
        set<int> st = q.top(); // first set in priority queue
        for (auto x : st)
            cout << x << " ";
        cout << "] ";
        q.pop();
    }
    cout << endl;
}

/* class person
{
public:
    int id;
    string name;
    person(int x, string s)
    {
        id = x;
        name = s;
    }
}; */
int main()
{
    // priority_queue<int> q; default priority queue is implemented on static queue
    // implementing using vectors for dynamic memory allocation
    priority_queue<int, vector<int>> q; // syntax: priority_queue<data_type,container<data_type>> object;
    q.push(34);
    q.push(56);
    q.push(67);
    q.push(75);
    q.push(24);
    q.push(47);
    display(q);

    // Min Heap Priority Queue (Reverse of Max Heap priority queue)
    // syntax: priority_queue<data_type,container<data_type>,function> object;
    priority_queue<int, vector<int>, greater<int>> q2; // For a queue with min heap properties, i.e items sorted in decreasing order
    q2.push(45);
    q2.push(15);
    q2.push(25);
    q2.push(95);
    q2.push(65);
    display(q2);

    // the priority queue can be implemented on sets,maps and lists
    priority_queue<set<int>> q3; // the priority queue will sort(increasing order) the items based on the first item of set
    set<int> v1;                 // by default set stores items in increasing order
    v1.insert(63);
    v1.insert(13);
    v1.insert(53);
    set<int> v2;
    v2.insert(45);
    v2.insert(67);
    v2.insert(14);
    q3.push(v1);
    q3.push(v2);
    display(q3);

    // Implementing priority queue in more optimised way
    int arr[] = {23, 67, 34, 92, 24};
    int n = sizeof(arr) / sizeof(int);
    // priority_queue<int> q4(arr, arr + 5);
    priority_queue<int, vector<int>> q4(arr, arr + n); // iterator position of 1st and last element in array
    display(q4);

    // Implementing priority queue with custom data type using class
    /* person p1(24, "shubh");
    person p2(57, "ram");
    person p3(45, "harsh");
    priority_queue<person, vector<person>> q5;
    q5.push(p1);
    q5.push(p2);
    q5.push(p3); */

    priority_queue<int, vector<int>> qt;
    qt.push(23);
    qt.push(22);
    qt.push(33);
    qt.push(43);
    display(qt);
    qt.pop();
    display(qt);
    cout << qt.top();
    return 0;
}