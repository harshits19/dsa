#include <iostream>
#include <queue>
using namespace std;
/*
    Eg. [20,10,5,30,100]
        sum=35
        max items we can buy = 3 =>{20 + 10 + 5 = 35}
        sum of item values < sum
 */

void buyMaxItems(int *arr, int n, int sum)
{
    priority_queue<int, vector<int>, greater<int>> q; // for a minHeap priority queue(sorts in ascending orders)
    int count = 0;
    int i = 0;
    for (int i = 0; i < n; i++)
        q.push(arr[i]);

    while (sum >= 0)
    {
        if (q.top() <= sum)
        {
            count++;
            sum = sum - q.top();
            q.pop();
        }
        else
            break;
    }
    cout << "Max Items : " << count << endl;
}
int main()
{
    int arr[] = {10, 9, 7, 8, 4, 70, 50, 60};
    int sum = 40;
    int n = sizeof(arr) / sizeof(int);
    buyMaxItems(arr, n, sum);

    return 0;
}