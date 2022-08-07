#include <iostream>
using namespace std;

int BinarySearch(int *arr, int size, int num)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
void Sorting(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void showArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int recBinarySearch(int *arr, int num, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + (high - 1)) / 2;
        if (arr[mid] == num)
            return mid;
        if (arr[mid] > num)
            return recBinarySearch(arr, num, low, mid - 1);
        else
            return recBinarySearch(arr, num, mid + 1, high);
    }
    return -1;
}

int main()
{
    int arr[] = {32, 93, 56, 22, 14, 64, 74, 67, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num, result;
    showArray(arr, n);
    Sorting(arr, n);
    showArray(arr, n);
    cout << "Enter Element to be Searched : ";
    cin >> num;
    result = BinarySearch(arr, n, num);
    if (result >= 0)
        cout << "Element present at " << result + 1 << " position";
    else
        cout << "Element does not present in Array";

    return 0;
}