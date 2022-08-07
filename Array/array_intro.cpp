#include <iostream>
#define CP 10
// capacity of array
using namespace std;

/* Methods for declaring array-
Fixed Size Array
int arr[]={23,45,65}; //static memory allocation
int arr[n];           //Stored in Stack

int *arr =  new int[n]; //dynamic memory allocation, Stored in heap

Variable Size Array
vector<int> arr;

Operations:
search an element time: O(n)
insert/delete an element at any given position  time:O(n)

*/
/*   0 1 2 3 4 5 6 7 8
    [3,5,7,4,9,6, , , ] size=6 cap=9
    insert 8 at 4
    [3,5,7,4,8,9,6, , ] size=7 cap=9

    a[s+1]=a[s]
    s--;

 */
int getSize(int *arr)
{
    int count = 0;
    for (int i = 0; i < CP; i++)
        if (arr[i] != 0)
            count++;
    return count;
}
void insert(int *arr, int val, int pos)
{
    int size = getSize(arr);
    if (size == CP)
    {
        cout << "Array Overflow" << endl;
        return;
    }
    for (int i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
}
void deleteVal(int *arr, int val)
{
    int i;
    int size = getSize(arr);
    for (i = 0; i < size; i++)
    {
        if (arr[i] == val)
            break;
    }
    while (i < size)
    {
        arr[i] = arr[i + 1];
        i++;
    }
}
int search(int *arr, int num)
{
    int low = 0, high = getSize(arr);
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
void display(int *arr)
{
    int size = getSize(arr);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[CP] = {23, 45, 67, 56, 75, 43, 70};
    display(arr);
    insert(arr, 35, 5); // arr,val,pos
    display(arr);
    deleteVal(arr, 67); // arr,val
    display(arr);
    int s = search(arr, 75);
    cout << "Is 75 present? " << (s > 0 ? "true" : "false") << endl;
    return 0;
}