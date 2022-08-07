#include <iostream>
#include <deque>
using namespace std;
void display(deque<int> dq)
{
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
}

int main()
{

    deque<int> dq;
    dq = {23, 54}; // Alternate Way
    dq.push_front(23);
    dq.push_front(94);
    dq.push_back(54);
    dq.push_back(46);
    for (auto x : dq) // Alternate Shortcut Method
        cout << x << " ";
    cout << endl;
    auto it = dq.begin(); // it returns the iterator pointing to front of deque
    it++;
    dq.insert(it, 45);
    display(dq);
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    return 0;
}