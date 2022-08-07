#include <iostream>
using namespace std;

int startingOccurence(int *arr, int size, int num)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] > num)
            high = mid - 1;
        else if (arr[mid] < num)
            low = mid + 1;
        else
        {
            if ((mid == 0) || (arr[mid - 1] != arr[mid]))
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int lastOccurence(int arr[], int size, int num)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < num)
            low = mid + 1;
        else if (arr[mid] > num)
            high = mid - 1;
        else
        {
            if (mid == size - 1 || arr[mid] != arr[mid + 1])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}
int countOccurence(int *arr, int size, int num)
{
    int first = startingOccurence(arr, size, num);
    if (first == -1)
        return 0;
    else
        return (lastOccurence(arr, size, num) - first + 1);
}

int main()
{
    int arr[] = {10, 12, 15, 17, 17, 17, 19, 19, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num = 19;
    int res = startingOccurence(arr, n, num);
    cout << "starting occurence : " << res << endl;
    int result = lastOccurence(arr, n, num);
    cout << "last occurence : " << result << endl;
    int count = countOccurence(arr, n, num);
    cout << "count occurence : " << count << endl;
    return 0;
}