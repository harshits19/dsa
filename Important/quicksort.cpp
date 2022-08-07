#include <iostream>
#include <vector>
using namespace std;

// tc : O(nlogn) for all cases, and Space : O(1)

int partition(vector<int> &arr, int low, int high)
{
    int i = low, j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int main()
{
    vector<int> arr = {23, 45, 75, 26, 98, 34, 74, 16, 41};
    for (auto a : arr)
        cout << a << " ";
    cout << endl;
    quick_sort(arr, 0, arr.size() - 1);
    for (auto a : arr)
        cout << a << " ";
    return 0;
}