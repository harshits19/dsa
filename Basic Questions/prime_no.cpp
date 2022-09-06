#include <iostream>
#include <vector>
using namespace std;
/*
Prime numbers are those which are divisible by 1 and itself only.
eg. 2,5,7,11,13,17,19,23,29
*/

// Naive Solution, Time: O(n)
bool isPrime(int num) {
    if (num == 1)
        return false;
    for (int i = 2; i < num; i++) // checking for n=2 to n-1 if number is divisible by any of the non prime numbers then it is non prime
    {
        if (num % i == 0)
            return false;
    }
    return true; // if it is not divisible by any number then it should be prime
}

/*
a prime number should not be divisible by 2 or 3 for all cases
Prime no occur in pairs like 29 = (1,29), 37 = (1,37), 43(1,43)
non prime numbers occurs also occurs in multiple pairs like 24 = (1,24),(2,12),(3,8),(4,6)
we can say that for a pair(x,y), x*y = n
    if x<=y, then x*x<=n then x <= root(n)
    we need to check only till the root of n , because the divisor below the root(n) can have a pair

*/
// Efficient Solution, Time: O(root(n))
bool primeCheck(int num) {
    if (num == 1)
        return false;
    for (int i = 2; i * i <= num; i++) // i < root(num) == i*i < num
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Improved Solution
bool primeImproved(int num) {
    if (num == 1)
        return false;
    if (num == 2 || num == 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}
int main() {
    int n = 25, q = 37, r = 229;
    cout << n << " is Prime : " << (isPrime(n) > 0 ? "True" : "False") << endl;
    cout << q << " is Prime : " << (primeCheck(q) > 0 ? "True" : "False") << endl;
    cout << r << " is Prime : " << (primeImproved(r) > 0 ? "True" : "False") << endl;

    // print prime numbers between 1 to n
    int k = 100;
    vector<int> res;
    for (int i = 1; i < k; i++)
        if (primeImproved(i))
            res.push_back(i);

    for (auto a : res)
        cout << a << " ";

    return 0;
}