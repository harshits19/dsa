#include <iostream>
using namespace std;

class num2str
{
    bool palindrom(string S)
    {
        int s = 0, e = S.size() - 1;
        while (s <= e)
        {
            if (S[s++] != S[e--])
                return 0;
        }
        return 1;
    }

public:
    int PalinArray(int a[], int n) // converting number to string
    {
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            while (a[i])
            {

                temp += char(a[i] % 10) - 'A';
                a[i] /= 10;
            }
            if (!palindrom(temp))
                return 0;
            temp = "";
        }
        return 1;
    }
};

int main()
{
    // 1 = true (palindrome string) , 0 = false (non palindrome array) GFG Qn
    num2str a;
    int arr[] = {232, 1111, 222, 44444, 777};
    cout << a.PalinArray(arr, 5);
    return 0;
}