#include <iostream>
using namespace std;

void reverse(string &s, int beg, int end)
{
    while (beg <= end)
    {
        int temp = s[beg];
        s[beg] = s[end];
        s[end] = temp;
        beg++;
        end--;
    }
}

void reverseWords(string &str, int n)
{
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (str[end] == ' ') //detecting spaces in string
        {
            reverse(str, start, end - 1); //Reversing each word
            start = end + 1;              //assign start to next character after space i.e. first character of another word
        }
    }
    //after out of the loop, the value of start would be first character of last word
    //we come out of loop because after last word there is no space, so we need to reverse it outside
    reverse(str, start, n - 1); //reversing the last word
    reverse(str, 0, n - 1);     //reversing the whole string from beginning to end
}

int main()
{
    string str = "MOMY DADY SISY TOBY";
    int n = str.size();
    cout << str << endl;
    reverseWords(str, n);
    cout << str << endl;

    return 0;
}