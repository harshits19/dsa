#include <iostream>
#include <vector>
using namespace std;

// tc is O(nlogn) for best and average case, O(n^2) for worst case, space : O(n)

void merge(vector<int> &arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    vector<int> res(arr.size());
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            res[k++] = arr[i++];
        else
            res[k++] = arr[j++];
    }
    if (i > mid) // when one of the sub array is traversed till the end
        while (j <= high)
            res[k++] = arr[j++];
    else
        while (i <= mid)
            res[k++] = arr[i++];
    for (k = low; k <= high; k++)
        arr[k] = res[k];
}
void merge_sort(vector<int> &arr, int low, int high)
{
    if (low < high) // break until two elements
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 1, 0, 5, 9, 6, 8};
    for (auto a : arr)
        cout << a << " ";
    cout << endl;
    merge_sort(arr, 0, arr.size() - 1);
    for (auto a : arr)
        cout << a << " ";
    return 0;
}