#include <iostream>
using namespace std;
/*
Dynamic Programming is an algorithmic approach to solve some complex problems easily and save time and number of comparisons by storing the results of past computations.
The basic idea of dp is to store the results of previous calculation and reuse it in future instead of recalculating them.

There are two different ways to store the values so that these values can be reused:
Memoization (Top Down)
Tabulation (Bottom Up)

Memoization (Top Down): The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions. We initialize a lookup array with all initial values as NIL. Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it can be reused later.

Tabulation (Bottom Up): The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on. So literally, we are building the solutions of subproblems bottom-up.

 */

int fib_memo(int n)
{
    int memo[100];
    for (int i = 0; i < 100; i++)
        memo[i] = -1;
    if (memo[n] == -1)
    {
        if (n <= 1)
            memo[n] = n;
        else
            memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    }
    return memo[n];
}
int fib_tab(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
int main()
{
    int n1 = 25, n2 = 37;
    cout << "Fib 8 : " << fib_memo(8) << endl;
    cout << "Fib 10 : " << fib_tab(10) << endl;
    return 0;
}