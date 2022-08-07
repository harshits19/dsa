#include <iostream>
#include <stack>
using namespace std;
void showstack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    // STL Stack Class
    stack<int> s1;
    s1.push(23);
    s1.push(45);
    s1.push(76);
    s1.push(83);
    s1.push(72);
    showstack(s1);
    s1.pop();
    s1.pop();
    s1.pop();
    showstack(s1);

    return 0;
}