#include <iostream>
using namespace std;
//Anagram means : comparing the two strings must contain same no of characters ,and their order can be different
//eg. AMALGAM -> LAGAMAM both strings are anagram, as they contain same no and type of characters, but arranged in different sequence

void sort(string &str, int n) //here passing refrence of string because we want the changes done in local string must reflect in passed string
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
bool isAmagram(string str, string str2) //naive solution
{
    sort(str, str.size());
    sort(str2, str2.size());
    return (str == str2); //it returns 1 if true, 0 if false
}
bool itsAmagram(string s1, string s2) //efficient solution with time complexity o(n)
{
    int count[256] = {0}; //taking size 256 so that it covers all ASCII alphabets,numbers and symbols
    if (s1.size() != s2.size())
        return false;
    else
    {
        for (int i = 0; i < s1.size(); i++)
        {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for (int i = 0; i < 256; i++)
        {
            if (count[i] != 0)
                return false;
        }
        return true;
    }
}

int main()
{
    string str1 = "BANANA";
    string str2 = "ANNBAA";
    cout << (itsAmagram(str1, str2) == 1 ? "true" : "false");
    return 0;
}