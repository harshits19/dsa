#include <iostream>
#include <deque>
using namespace std;
// Create a data structure which is speciallized in storing and accessing the minimum and maximum values in O(1) time

struct MyStr
{
    deque<int> dq;
    MyStr() {}
    void insertMin(int x) { dq.push_front(x); } // the min element added to front of deque
    void insertMax(int x) { dq.push_back(x); }  // the max element added to last of deque
    void extractMin() { dq.pop_front(); }       // delete the first node
    void extractMax() { dq.pop_back(); }        // delete the last node
    int getMin() { return dq.front(); }
    int getMax() { return dq.back(); }
    void display()
    {
        for (auto x : dq)
            cout << x << " ";
        cout << endl;
    }
};
int main()
{
    MyStr s;
    s.insertMax(15); //[15]
    s.insertMax(20); //[15|20]
    s.insertMax(30); //[15|20|30]
    s.insertMin(12); //[12|15|20|30]
    s.insertMin(10); //[10|15|20|30]
    s.display();
    cout << "Min: " << s.getMin() << endl;
    cout << "Max: " << s.getMax() << endl;

    return 0;
}