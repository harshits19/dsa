#include <iostream>
using namespace std;

void show(int *arr, int);

void mergeArr(int *ar, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = ar[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = ar[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            ar[k++] = left[i++];
        else
            ar[k++] = right[j++];
    }
    while (i < n1)
        ar[k++] = left[i++];
    while (j < n2)
        ar[k++] = right[j++];
}

void mergeSort(int *arr, int low, int high)
{
    if (high > low)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeArr(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {23, 43, 56, 34, 49, 24, 54, 76, 45};
    //int arr[] = {23, 34, 45, 66, 67, 78, 98};
    int l = 0, r = 8;
    int n = sizeof(arr) / sizeof(int);
    cout << "Array Before Sorting : ";
    show(arr, n);

    mergeSort(arr, l, r);

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