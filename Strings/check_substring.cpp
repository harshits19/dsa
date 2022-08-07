#include <iostream>
using namespace std;

/* A substring is a sequence of string
a n-length string contains 2^n subsequences
eg. ABC = {' ','a','b','c','ab','bc','ac','abc'} here n = 3, so possible sub sequence = 2^3 = 8;
diffrence : substring means array of contageous characters i.e. substring of ABC -> 'bc', 'ac' can't be a substring of ABC;
the subsequence must be in same order with the string,also there it can be non contageous, i.e. subsequence of ABC -> 'ac'
*/
bool isSubstr(const string s1, const string s2)
{
    int j = 0;
    for (int i = 0; i < s1.length() && j < s2.length(); i++)
    {
        if (s1[i] == s2[j])
            j++;
    }
    return (j == s2.length());
}
bool isSubstr2(const string s1, const string s2, int m, int n) // m = length of s1 , n = length of s2
{
    if (n == 0) // if String s2 ends before s1 (n<m) then it means the s2 is substring of s1
        return true;
    if (m == 0) // if s1 ends before s2, then s2 is not ended, hence s2 is not a substring of s1
        return false;
    if (s1[m - 1] == s2[n - 1])
        return isSubstr2(s1, s2, m - 1, n - 1);
    else
        return isSubstr2(s1, s2, m - 1, n);
}
int main()
{
    string s1 = "ahbgdc";
    string s2 = "abc";
    int m = s1.size(), n = s2.size();
    if (isSubstr(s1, s2) == true)
        // if (isSubstr2(s1, s2, m, n) == true)
        cout << "True";
    else
        cout << "False";

    return 0;
}