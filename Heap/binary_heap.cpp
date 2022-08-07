#include <iostream>
using namespace std;
/*
A Heap is a Tree-based data structure, which satisfies the below properties:
A Heap is a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible).

A Heap is either Min Heap or Max Heap.
In a Min-Heap, the key at root must be minimum among all keys present in the Binary Heap. The same property must be recursively true for all nodes in the Tree. Max Heap is similar to MinHeap.

Binary Heap:
A Binary Heap is a heap where each node can have at most two children. In other words, a Binary Heap is a complete Binary Tree satisfying the above-mentioned properties.

Since a Binary Heap is a complete Binary Tree, it can be easily represented using Arrays.
The root element will be at Arr[0].
Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:
Arr[(i-1)/2]	Returns the parent node
Arr[(2*i)+1]	Returns the left child node
Arr[(2*i)+2]	Returns the right child node

 */
struct heap
{
    int *arr;
    int size, cap;
    heap(int cap)
    {
        this->cap = cap;
        int *arr = new int[cap];
        size = 0;
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    void insert(int dat)
    {
        if (size == cap)
        {
            cout << "Heap Full";
            return;
        }
        else
        {
            size++;
            arr[size - 1] = dat;
            for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
            {
                swap(arr[parent(i)], arr[i]);
                i = parent(i);
            }
        }
    }
    void display()
    {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
void insertNode(int *arr, int size, int val)
{
    size += 1;                       // Increase the size of Heap by 1
    arr[size - 1] = val;             // Insert the element at end of Heap
    maxHeapify(arr, size, size - 1); // Heapify the new node following a Bottom-up approach
}
void maxHeapify(int *arr, int n, int i)
{
    int parent = (i - 1) / 2; // Find parent
    if (parent >= 0)
    {
        // For Max-Heap If current node is greater than its parent Swap both of them and call heapify again for the parent
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            maxHeapify(arr, n, parent); // Recursively heapify the parent node
        }
    }
}

int main()
{
    heap ary(10);
    ary.insert(21);
    ary.insert(34);
    ary.insert(56);
    ary.insert(14);
    ary.display();
    return 0;
}