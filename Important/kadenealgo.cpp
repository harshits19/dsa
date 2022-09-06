#include <iostream>

using namespace std;
// Kadene's algorithm's main application is in finding the maximum length subarray whose elements have maximum sum
// tc : O(n)

// brute force : tc O(n^3)
// finding all possible sub arrays and then selecting the one which has the max sum
// in this case arr[] .... the sub array would be {4,-1,2,1}

int naiveMaxSubarray(int *arr, int n) {
    int maxSum = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i; j < n; j++) {
            int currSum = 0;
            for (int k = i; k <= j; k++) {
                currSum += arr[k];
            }
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

// tc : O(n)
int maxSubarraySum(int *arr, int n) {
    int maxSum = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}

// another O(n) approach
int maxSubarraySumTwo(int *arr, int n) {
    int endSum = arr[0];
    int currSum = arr[0];
    for (int i = 1; i < n; i++) {
        endSum = max(endSum + arr[i], arr[i]);
        currSum = max(currSum, endSum);
    }
    return currSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << naiveMaxSubarray(arr, n) << endl;
    cout << maxSubarraySum(arr, n) << endl;
    cout << maxSubarraySumTwo(arr, n) << endl;
    return 0;
}
/*
Kadene's Algo Approach
Initially
currSum(c) = 0
maxSum(m) = 0

on single iteration of loop on whole array
1.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
      ⇧
    c = -2 , m = 0 (-2 < 0)
    c = 0 (-2<0)

2.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
         ⇧
        c = 0 + 1 = 1, m = 1 (1 > 0)

3.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
             ⇧
        c = 1 - 3 = -2 , m = 1 (-2 < 1)
        c = 0 (-2 < 0)

4.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
                ⇧
        c= 0 + 4 = 4 , m = 4 (4 > 1)

5.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
                    ⇧
        c= 4 - 1 = 3, m = 4 (3 < 4)

6.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
                       ⇧
        c= 3+2 = 5, m = 5 (5 > 4)

3.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
                          ⇧
        c= 5 + 1 = 6, m = 6 ( 6 > 5)

3.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
                              ⇧
        c= 6 - 5 = 1, m =6 (1 < 6)

3.  [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
                                 ⇧
        c = 1 + 4 = 5, m =6 (5 < 6)

    maxSum(m) = 6
 */
