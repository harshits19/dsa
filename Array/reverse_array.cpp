#include <iostream>
#define CP 7
using namespace std;
int getSize(int *arr)
{
    int count = 0;
    for (int i = 0; i < CP; i++)
        if (arr[i] != 0)
            count++;
    return count;
}
void display(int *arr)
{
    int size = getSize(arr);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void reverseArray(int *arr)
{
    int size = getSize(arr);
    int i = 0, j = size - 1;
    while (i < j)
    {
        swap(arr, i, j);
        i++;
        j--;
    }
}
int main()
{
    int arr[CP] = {23, 45, 67, 56, 75, 43, 70};
    display(arr);
    reverseArray(arr);
    display(arr);
    return 0;
}