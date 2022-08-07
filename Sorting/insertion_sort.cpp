#include <iostream>
using namespace std;
//stable and inplace algorithm
//best case : array is already sorted : o(n)
//worst case : array is reverse sorted : theta(n^2)
//in general : theta(n^2)
//used in small array sorting in other algorithms like merge ,tim, intro sorts

void show(int *arr, int);

void insertionsort(int *A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int arr[] = {67, 43, 56, 34, 49, 24, 54, 76, 45};
    //int arr[] = {23, 34, 45, 66, 67, 78, 98};
    int n = sizeof(arr) / sizeof(int);

    cout << "Array Before Sorting : ";
    show(arr, n);

    insertionsort(arr, n);

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