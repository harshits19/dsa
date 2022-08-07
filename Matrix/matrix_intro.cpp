#include <iostream>
#include <vector>

using namespace std;

// Matrix is a multi dimension array
void display(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "-----------" << endl;
}

void display(int *arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << *((arr + i * n) + j) << " ";
        cout << endl;
    }
    cout << "-----------" << endl;
}
void display2(int *arr[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "-----------" << endl;
}
void display(vector<vector<int>> &arr) // Improved
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "-----------" << endl;
    /*
    for (vector<int> vect1D : vect){
        for (int x : vect1D)
            cout << x << " ";
        cout << endl;
    }
    */
}
/* void display(vector<vector<int>> arr, int m, int n)
{   for (int i = 0; i < m; i++)
    {   for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;}
} */

int main()
{
    // 2D Array
    // Statically Allocated
    int arr1[3][3] = {23, 45, 65, 67, 24, 56, 43, 45, 23};
    /*  for (int i = 0; i < 3; i++)
        {   for (int j = 0; j < 3; j++)
                cout << arr1[i][j] << " ";
            cout << endl;
        } */
    display((int *)arr1, 3, 3); // we have to typecast the array into the pointer
    // display(&arr1[0][0], 3, 3); can be used

    /*  the elements are stored in row major order
        int arr1[][3] = {{23, 45, 65},{67, 24, 56}, {43, 45, 23}}; Internal curly brackets are optional
        int arr[][n] the first dimension parameter can be left blank while declaration , but second can't be left blank

        Variable sized array;
        int m=2,n=2;
        int arr2[m][n]; */

    // Dynamically Allocated
    // Method 1 : double pointers
    /* An array of pointers(row) which stores the the address of other pointers(which stores the address of column arrays)

                        0     n-1
        arr-> 0 [ ] -> [ , , , ]
                [ ] -> [ , , , ]
                [ ] -> [ , , , ]
            m-1 [ ] -> [ , , , ]

    */
    int m = 3, n = 3;
    int **arr3;          // creating a pointer which stores the address of rows
    arr3 = new int *[m]; // allocating space for rows, the arr will store the address of starting row
    for (auto i = 0; i < m; i++)
        arr3[i] = new int[n]; // allocating space for columns, the arr rows will store the address of the starting column
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            arr3[i][j] = i + j;
    }
    display(arr3, m, n);

    // Method 2 : Array of pointers
    int *arr4[m];
    for (int i = 0; i < m; i++)
    {
        arr4[i] = new int[n]; // the index in array will store the location of columns
        for (int j = 0; j < n; j++)
            arr4[i][j] = j + i * j;
    }
    display2(arr4, m, n);

    // Method 3 : using vectors
    vector<vector<int>> row;
    for (size_t i = 0; i < m; i++)
    {
        vector<int> col;
        for (size_t j = 0; j < n; j++)
            col.push_back(i + j * 2);
        row.push_back(col);
    }
    //   display(row, m, n);
    display(row);
    /*
        We create a 2D vector containing "n"
        elements each having the value "vector<int> (m, 0)".
        "vector<int> (m, 0)" means a vector having "m"
        elements each of value "0".
        Here these elements are vectors.
        vector<vector<int>> vec( n , vector<int> (m, 0));
     */

    //    vector<vector<int>> arr={{1},{1,1},{1,1,1}}; shorthand of assigning value to 2d vector
    return 0;
}