#include <iostream>
using namespace std;

class myHash
{
public:
    int *arr;
    int cap, size;
    myHash(int c) // initialize the hashing class
    {
        cap = c;
        arr = new int[c];
        size = 0;
        for (size_t i = 0; i < cap; i++)
            arr[i] = -1;
    }
    int hash(int key)
    {
        return (key % cap);
    }
    void show()
    {
        for (size_t i = 0; i < cap; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    bool insert(int key)
    {
        if (size == cap)
            return false;
        int i = hash(key);
        while ((arr[i] != -1) && (arr[i] != -2) && (arr[i] != key))
            i = (i + 1) % cap;
        if (arr[i] == key)
            return false;
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
    }
    void search(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1) // search until we find empty space(-1) in slot
        {
            if (arr[i] == key)
            {
                cout << "Value " << key << " at index " << i << endl;
                return;
            }

            i = (i + 1) % cap; // traversing in the circular way
            if (i == h)        // when list is full and element not found, then we stop at the beginning slot of table
            {
                cout << key << " not found !" << endl;
                return;
            }
        }
        cout << key << " not found !" << endl;
    }
    bool erase(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1) // search until we find empty space(-1) in slot
        {
            if (arr[i] == key)
            {
                arr[i] = -2; //-2 means deleted slot,which can be used for inserting new values
                return true;
            }
            i = (i + 1) % cap; // traversing in the circular way
            if (i == h)        // when list is full and element not found, then we stop at the beginning slot of table
                return false;
        }
        return false;
    }
};

int main()
{
    myHash m(7);
    m.insert(35);
    m.insert(82);
    m.insert(78);
    m.insert(23);
    m.insert(36);
    m.show();
    m.search(36);
    m.erase(78);
    m.show();
    return 0;
}