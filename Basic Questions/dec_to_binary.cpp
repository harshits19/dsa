#include <iostream>
using namespace std;
void decToBinary(int n) {
    int binaryNum[32];
    // counter for binary array
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2; // storing remainder in binary array
        n = n / 2;
        i++;
    }
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
int main() {
    int n = 17;
    decToBinary(n);
    return 0;
}