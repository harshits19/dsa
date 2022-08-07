#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &vec)
{
    int m = vec.size();
    int n = vec[0].size();
    vector<vector<int>> row(m, vector<int>(n, 0));
    for (size_t i = 0; i < vec.size(); i++)
        for (size_t j = 0; j < vec[0].size(); j++)
            row[i][j] = vec[j][i];
    return row;
}

void display(vector<vector<int>> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec[0].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> vect;
    vect = {{1, 2, 3, 4}, {6, 3, 7, 4}, {5, 4, 3, 8}, {9, 6, 3, 1}};
    display(vect);
    cout << "After Transpose: " << endl;
    vect = transpose(vect);
    display(vect);
    return 0;
}