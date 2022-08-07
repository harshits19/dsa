#include <iostream>
using namespace std;
// Performing Basic Heap Operations such as:
// Insert, Delete, ExtractMin, Buildheap , Heapify
// on the min-heap
class heap
{
public:
    int *arr;
    int size, cap;
    heap(int cap)
    {
        this->cap = cap;
        size = 0;
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    void insert(int *arr, int);
    void display(int *arr, int);
    void buildMinHeap(int *arr, int);
    void minHeapify(int *arr, int, int);
    int extractMin(int *arr, int &size);
    void decreaseKey(int *arr, int, int);
    void deleteKey(int *arr, int, int &n);
};
void heap::display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void heap::insert(int *arr2, int n)
{
    size = n;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = arr2[i];
}
void heap::minHeapify(int *arr, int n, int i) // heapifying from parent to child
{
    int smallest = i; // initially assuming parent (i) is smallest element
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // checking if left or right child node is smallest
    if (left < n && arr[smallest] > arr[left])
        smallest = left; // if true, then assign child node as smallest
    if (right < n && arr[smallest] > arr[right])
        smallest = right;
    if (smallest != i) // if smallest is one of the child node then swap it with (i)th (parent) node
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest); // again call for the subtree
    }
}
void heap::buildMinHeap(int arr[], int n)
{
    /*
    last node = (n - 1) index
    parent of last node = ((n - 1) - 1)/2   =>      (n-2)/2
    */
    int startIdx = (n - 2) / 2; // start building heap from parent of last node (i.e a non leaf node)
    for (int i = startIdx; i >= 0; i--)
        minHeapify(arr, n, i);
}
int heap::extractMin(int *arr, int &n)
{
    if (n == 0) // corner case: when there is an empty heap
        return 0;
    if (n == 1) // if only single item present in heap then return it and decrease the size of heap
    {
        return arr[0];
        n--;
    }
    // In a min heap, the first item is always a smallest one, hence swap it with last one and return the last item
    swap(arr[0], arr[n - 1]); // swap first and last item of heap
    n = n - 1;                // decrease the size of heap
    minHeapify(arr, n, 0);    // heapify the heap from first item
    return arr[n];            // return the last item which is the min value
}
void heap::decreaseKey(int *arr, int i, int val)
{
    arr[i] = val;                             // replace the value of item at the given index
    while (i != 0 && arr[parent(i)] > arr[i]) // now heapify the Btree until it follow all properties of heap
    {
        swap(arr[parent(i)], arr[i]); // heapifying from botttom to up (child to parent)
        i = parent(i);
    }
}

void heap::deleteKey(int *arr, int i, int &n)
{
    decreaseKey(arr, i, INT_MIN); // changing the value to (-infinity) of item which has to be deleted and heapify the BTree
    extractMin(arr, n);           // Now extracting the min value (i.e -infinity) out of heap and heapify it
                                  // As a result , we get a heap without the value which we want to delete
}

int main()
{
    int arr[] = {17, 15, 13, 9, 6, 5, 10, 4, 8, 3, 1};
    int n = sizeof(arr) / sizeof(int);
    heap h(n);
    h.display(arr, n);                    // 17 15 13 9 6 5 10 4 8 3 1
    h.buildMinHeap(arr, n);               //
    h.display(arr, n);                    // 1 3 5 4 6 13 10 9 8 15 17
    cout << h.extractMin(arr, n) << endl; // 1
    h.display(arr, n);                    // 3 4 5 8 6 13 10 9 17 15
    h.decreaseKey(arr, 4, 1);             // (array,index,value)
    h.display(arr, n);                    // 1 3 5 8 4 13 10 9 17 15
    h.deleteKey(arr, 6, n);               // (array,index,array_Size)
    h.display(arr, n);                    // 1 3 5 8 4 13 15 9 17

    return 0;
}
/*  1. Build Heap                                   Min heap
                17                                       1
               /  \                                    /  \
             15    13                                 3    5
            /  \  /  \                              /  \  / \
           9   6 5   10                            4   6 13  10
         / \  / \                                / \  / \
        4  8 3  1                               9  8 15 17

    2. Extract Min
                1                                       3
              /  \                                    /  \
             3    5                                  4    5
           /  \  / \           ---->               /  \  / \
          4   6 13 10                             8   6 13 10
        / \  / \                                / \   |
       9  8 15 17                              9  17 15

    3. Decrease Key (4, 1) (index,key_value)

                3                                       1
              /  \                                    /  \
             4    5                                  3    5
           /  \  / \           ---->               / \   / \
          8   6 13 10                             8  4  13 10
        / \   |                                 / \  |
       9  17 15                                9 17 15

    4. Delete (6) (index)
                1                                       1
              /  \                                    /  \
             3    5                                  3    5
           /  \  / \           ---->               / \   / \
          8   4 13 10                             8  4  13 15
        / \   |                                  / \
       9  17 15                                 9  17
 */