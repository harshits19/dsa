#include <iostream>
#include <list>
using namespace std;

struct hashT
{
    int size;
    list<int> *table;
    hashT(int x)
    {
        size = x;
        table = new list<int>[size];
    }
    void insert(int val)
    {
        int i = val % size;
        table[i].push_back(val);
    }
    void remove(int val)
    {
        int i = val % size;
        table[i].remove(val);
    }
};

int main()
{
    hashT h(10);

    return 0;
}