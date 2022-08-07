#include <iostream>
#include <string>
using namespace std;

int main()
{
    string abb = "harshitgaur";
    cout << abb << endl;
    int count[26] = {0}; //create array count to store counting of 26 alphabets
    for (int i = 0; i < abb.length(); i++)
        count[abb[i] - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
            cout << (char)(i + 'a')
                 << " -> " << count[i]
                 << (count[i] > 1 ? " times" : " time") << endl;
    }

    return 0;
}