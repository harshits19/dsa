#include <iostream>
using namespace std;
//Selection sort features
//time complexity - o(n^2) for all cases
//takes less memory compared to quick,merge,insertion sort
//cycle sort is best for memory management
//has basic idea of heap sort
//not stable sorting, it can dislocate the equal elements after sorting
//in place algo, it does not require extra memory for sorting

void swap(int *arr, int, int);
void show(int *arr, int);

void selectionsort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        swap(A, i, min);
    }
}

int main()
{

    int arr[] = {23, 43, 56, 34, 49, 24, 54, 76, 45};
    //int arr[] = {23, 34, 45, 66, 67, 78, 98};
    int n = sizeof(arr) / sizeof(int);

    cout << "Array Before Sorting : ";
    show(arr, n);

    selectionsort(arr, n);

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