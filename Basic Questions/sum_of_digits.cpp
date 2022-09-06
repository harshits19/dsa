#include <iostream>
using namespace std;
int main() {
    int number = 145;
    int sum = 0;
    while (number != 0) {
        int digit = number % 10;
        number = number / 10;
        sum += digit;
    }
    cout << sum << endl;
    return 0;
}