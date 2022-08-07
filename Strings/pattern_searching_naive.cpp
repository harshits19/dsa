#include <iostream>
using namespace std;

//naive method for searching pattern in a text
//time complexity : O(m-n + 1)*(n) , space complexity : O(1)
void isPattern(const string &txt, const string &pat)
{
    int m = txt.length();
    int n = pat.length();
    for (auto i = 0; i <= m - n; i++) //i runs till length of (text-pattern)
    {
        int j;
        for (j = 0; j < n; j++) //j runs till length of pattern
        {
            if (pat[j] != txt[i + j]) //if any character is mismatched while comparing text and pattern the loop will break
                break;
        }
        if (j == n)           //if no mismatching happens then value of j will become the length of pattern and it means the pattern is present in text
            cout << i << " "; //hence the i indicates the starting index of pattern in text
    }
}

//Improved naive method for searching pattern in a text having distinct characters
//here the characters are not repeated simultaneously like ABCDEFABCDE, ABABCDCDABCD
//time complexity : theta(n)
void isDistPat(const string &txt, const string &pat)
{
    int m = txt.length();
    int n = pat.length();
    for (auto i = 0; i <= m - n;)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (pat[j] != txt[i + j])
                break;
        }
        if (j == n)
            cout << i << " ";
        if (j == 0) //if loop terminates on starting index of text then it will check from next index in text
            i++;
        else //if loop terminates after passing more than one index but less that 'n' index then we shift  i to position i+j;
            i = i + j;
    }
}

int main()
{
    string txt = "AABABBAABAABAB";
    string pat = "AB";
    cout << txt << endl
         << pat << endl;
    isPattern(txt, pat);
    cout << endl;
    string txt2 = "ABCDMNOPABCD";
    string pat2 = "BCD";
    cout << txt2 << endl
         << pat2 << endl;
    isDistPat(txt2, pat2);
    return 0;
}