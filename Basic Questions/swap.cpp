#include <iostream>
using namespace std;
int main() {
    int a = 145;
    int b = 200;
    cout << a << " " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << " " << b << endl;
    return 0;
}