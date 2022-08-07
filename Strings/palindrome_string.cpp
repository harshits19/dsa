#include <iostream>
using namespace std;

//A palindrome string is something which remains same if we traverse it through reverse order
//eg ABCDCBA , BAACAAB , NMCCCCMN
// non palindrome are : ABCDBCD ,  MNOPQRS , PTQQPT

bool isPal(string &str) //passing refrence so that original string remains untouched
{
    int low = 0;
    int high = str.length() - 1;
    while (low <= high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

int main()
{

    string str = "AABBCCDCCBBAA";
    if (isPal(str) == true)
        cout << "True";
    else
        cout << "False";

    return 0;
}