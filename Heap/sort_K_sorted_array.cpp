#include <iostream>
#include <queue>
using namespace std;
/* K Sorted array
        An element at index (i) will be present between the index (i-k) to (i+k) in the sorted array.

         0 1 2  3  4  5
        [9,8,7,18,19,17]
        K=2
        suppost i=3
        sort the array such that the possible position of 18 can be shifted (+-2) from current index (i=3)
        i.e 18 can be shifted to 1,2 or 4,5 , or it can remain at its original index
        Output:-
        [7,8,9,17,18,19]

        [10,9,7,8,4,70,50,60]
        K=4
        [4,7,8,9,10,50,60,70]
 */

void sortEff(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> q; // for a minHeap priority queue(sorts in ascending orders)
    for (int i = 0; i <= k; i++)                      // loop runs for k times
        q.push(arr[i]);
    int index = 0;
    for (int i = k + 1; i < n; i++) // loop runs for (n-k) times
    {
        arr[index++] = q.top(); // inserting the smallest item(top) in heap into array from start(i=0) to (i=k) item of array one by one,also incrementing index of array (i++) simultaneously
        q.pop();                //  popping out the top/smallest item from heap
        q.push(arr[i]);         // pushing the elements of array from index(k+1) to (n-1) into heap one by one
    }
    while (!q.empty()) // inserting the leftover elements in heap after (i=k) in the array
    {
        // At start (index=k), it will increase until heap is empty (i.e all the items are popped and inserted into array)
        arr[index++] = q.top(); // inserting the top/smallest element in heap first into the array at index=k, then incrementing index by 1
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    // int arr[] = {9, 8, 7, 18, 19, 17}; int k = 2;
    int arr[] = {10, 9, 7, 8, 4, 70, 50, 60};
    int k = 4;
    int n = sizeof(arr) / sizeof(int);
    sortEff(arr, n, k);

    return 0;
}