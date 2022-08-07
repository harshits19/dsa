#include <iostream>
#include <vector>
using namespace std;
void display(vector<vector<int>> &arr) // Improved
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "-----------" << endl;
}
void snakePat(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < arr[i].size(); j++)
                cout << arr[i][j] << " ";
        else
            for (int j = arr[i].size() - 1; j >= 0; j--)
                cout << arr[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int m = 5, n = 5;
    vector<vector<int>> row;
    for (size_t i = 0; i < m; i++)
    {
        vector<int> col;
        for (size_t j = 0; j < n; j++)
            col.push_back(j + 1);
        row.push_back(col);
    }
    display(row);
    snakePat(row);
    return 0;
}