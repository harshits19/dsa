#include <iostream>
#include <stack>
using namespace std;
bool maching(char, char);
bool isBalancedParenthesis(string str)
{
    if (str.size() == 0)
        return false;
    stack<char> s;
    for (int i = 0; i < str.size(); i++) // checking the string, character by character
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') // if there is opening bracket then push it into stack
            s.push(str[i]);
        else // now checking for condition if not open bracket then check for closed bracked in stack
        {
            if (s.empty() == true) // if stack is empty then it means the string would be containing closed bracked first
                return false;
            else if (maching(s.top(), str[i]) == false)
                return false;
            else // if both above conditions are not true then pop out the last character pushed into the stack (i.e one pair of brackets is processed)
                s.pop();
        }
    }
    return (s.empty() == true);
}
bool maching(char a, char b)
{
    return ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'));
}

int main()
{
    string s1 = "[{()}]";
    cout << s1 << endl;
    cout << (isBalancedParenthesis(s1) > 0 ? "True" : "False") << endl;
    s1 = "[(())";
    cout << s1 << endl;
    cout << (isBalancedParenthesis(s1) > 0 ? "True" : "False") << endl;
    s1 = "[{(})]";
    cout << s1 << endl;
    cout << (isBalancedParenthesis(s1) > 0 ? "True" : "False") << endl;
    return 0;
}