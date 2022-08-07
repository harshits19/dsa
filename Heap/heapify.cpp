#include <iostream>
using namespace std;
class heap
{
public:
    int *arr;
    int size, cap;
    heap(int cap)
    {
        this->cap = cap;
        size = 0;
        arr = new int[cap];
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    void insert(int);
    void display(void);
    void buildMaxHeap();
    void buildMinHeap();
    void maxHeapify(int);
    void minHeapify(int);
};
void heap::display()
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void heap::insert(int val)
{
    arr[size] = val;
    size++;
}
void heap::maxHeapify(int i) // i -> root item
{
    int largest = i; // initially assuming parent (i) is largest element
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // checking if left or right child node is largest
    if (left < size && arr[largest] < arr[left])
        largest = left; // if true, then assign child node as largest
    if (right < size && arr[largest] < arr[right])
        largest = right;
    if (largest != i) // if largest is one of the child node then swap it with (i)th (parent) node
    {
        swap(arr[i], arr[largest]);
        maxHeapify(largest); // again call for the subtree
    }
}
void heap::minHeapify(int i)
{
    int smallest = i; // initially assuming parent (i) is smallest element
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // checking if left or right child node is smallest
    if (left < size && arr[smallest] > arr[left])
        smallest = left; // if true, then assign child node as smallest
    if (right < size && arr[smallest] > arr[right])
        smallest = right;
    if (smallest != i) // if smallest is one of the child node then swap it with (i)th (parent) node
    {
        swap(arr[i], arr[smallest]);
        minHeapify(smallest); // again call for the subtree
    }
}

// the leaf nodes need not to be heapified as they already follow the heap property.
// So the idea is to find the position of the last non-leaf node and perform the heapify() of each non-leaf node in reverse level order.
void heap::buildMaxHeap()
{
    // Index of last non-leaf node
    int startIdx = (size - 2) / 2;
    for (int i = startIdx; i >= 0; i--)
        maxHeapify(i);
}
void heap::buildMinHeap()
{
    int startIdx = (size - 2) / 2;
    for (int i = startIdx; i >= 0; i--)
        minHeapify(i);
}
// total time complexity will be O(N*logN)
int main()
{
    int min_arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int max_arr[] = {17, 15, 13, 9, 6, 5, 10, 4, 8, 3, 1};
    int n = sizeof(max_arr) / sizeof(int);
    heap h(n);
    for (size_t i = 0; i < n; i++)
        h.insert(min_arr[i]);
    h.display();
    h.buildMaxHeap();
    h.display();
    return 0;
}
/*
          B Tree                         Max Heap
            1                               17
          /   \                           /   \
        3      5                        15     13
      /  \   /   \                     /  \   /  \
     4    6 13   10                   9    6 5   10
   /  \  / \                        / \  / \
  9   8 15  17                     4  8 3  1
 */