#include <iostream>
using namespace std;

//Checking whether string s1 is same as string s2 after rotating it clockwise or anti clockwise
//eg. check s1=ABAAC and s2=BAACA
//ABAAC -> CABAA -> ACABA -> AACAB ->BAACA (rotating anti clock wise)
//logic: if string s2 is a rotation of s1 then it can be found by concatinating the string s1 two times:
//eg. s1+s1= ABAACABAAC , hence it contain s2-> BAACA

bool isRotation(const string s1, const string s2)
{
    if (s1.size() != s2.size())
        return false;
    return ((s1 + s1).find(s2) != string::npos);
}
int main()
{
    string s1 = "ABAAC";
    string s2 = "BAACA";
    cout << (isRotation(s1, s2) == 1 ? "true" : "false");

    return 0;
}