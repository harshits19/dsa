#include <iostream>
using namespace std;

void show(int *arr, int);
void swap(int *arr, int, int);

int partition(int *arr, int low, int high)
{
    int pe = arr[low]; // pivot element
    int i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pe);
        do
        {
            j--;
        } while (arr[j] > pe);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}

int main()
{
    int arr[] = {23, 43, 56, 34, 49, 24, 54, 76, 45};
    int n = sizeof(arr) / sizeof(int);
    cout << "Array Before Sorting : ";
    show(arr, n);

    quickSort(arr, 0, n - 1);

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