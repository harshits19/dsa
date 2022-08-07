#include <iostream>
using namespace std;
//time complexity  = o(n^2)
//its a stable sorting algo bcoz it doesnt change the original order of the equal array elements after sorting

void swap(int *arr, int, int);
void show(int *arr, int);

void bubblesort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A, j, j + 1);
                isSorted = true;
            }
        }
        if (isSorted == false)
            break;
    }
}

int main()
{
    int arr[] = {92, 43, 56, 34, 49, 24, 54, 76, 45};
    //int arr[] = {23, 34, 45, 66, 67, 78, 98};
    int n = sizeof(arr) / sizeof(int);

    cout << "Array Before Sorting : ";
    show(arr, n);

    bubblesort(arr, n);

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