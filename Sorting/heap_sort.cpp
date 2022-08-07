#include <iostream>
using namespace std;

void swap(int *arr, int, int);
void show(int *arr, int);

void heapify(int *arr, int n, int t)
{
    int largest = t; //make target element 't' as largest
    int left = 2 * t + 1;
    int right = 2 * t + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != t)
    {
        swap(arr, t, largest);
        heapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr, 0, i);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {23, 45, 24, 35, 54, 95, 63, 84, 16, 73};
    int n = sizeof(arr) / sizeof(int);

    cout << "Array Before Sorting : ";
    show(arr, n);

    heapSort(arr, n);

    cout << "Array After Sorting : ";
    show(arr, n);

    return 0;
}
void show(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}