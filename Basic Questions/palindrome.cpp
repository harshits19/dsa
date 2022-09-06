#include <iostream>
using namespace std;
int reverse(int a) {
    int res = 0;
    while (a != 0) {
        int dig = a % 10;
        res = res * 10 + dig;
        a = a / 10;
    }
    return res;
}
int main() {
    int a = 1221;
    int b = reverse(a);
    if (a == b)
        cout << "Palindrome";
    else
        cout << "Not palindrome";
    return 0;
}
