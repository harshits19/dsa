#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
// Vector in C++ STL

void showvector(vector<int> vec)
{
    cout << "\nThe vector : ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

int main()
{

    vector<int> myvector;
    for (int i = 1; i <= 5; i++)
        myvector.push_back(i);

    vector<int>::iterator it; // declaring an iterator
    cout << "begin and end :";
    for (it = myvector.begin(); it != myvector.end(); ++it) // 1 2 3 4 5
        cout << *it << ' ';
    cout << "\nrbegin and rend : ";
    for (auto it = myvector.rbegin(); it != myvector.rend(); ++it) // 5 4 3 2 1
        cout << *it << " ";

    cout << "\nSize : " << myvector.size();                                         // 5
    cout << "\nCapacity : " << myvector.capacity();                                 // 8
    myvector.resize(4);                                                             // resizes the vector size to 4
    cout << "\nSize after resizing the vector by 4 elements : " << myvector.size(); // prints the vector size after resize()

    // empty() returns 0(false) if it's not empty and 1(true) if it's empty
    (myvector.empty() == 0) ? cout << "\nVector is not empty" : cout << "\nVector is empty";
    cout << "\nVector : ";
    for (auto it = myvector.begin(); it != myvector.end(); it++)
        cout << *it << " ";

    cout << "\nmyvector.at(2) = " << myvector.at(2);
    cout << "\nmyvector.front() = " << myvector.front();
    cout << "\nmyvector.back() = " << myvector.back();

    // Assign vector
    vector<int> v;

    // vectorname.assign(int size, int value)
    v.assign(5, 10); // fill the array with 10 five times
    showvector(v);   // 10 10 10 10 10

    v.push_back(15); // inserts 15 to the last position
    cout << "\nThe last element is: " << v[v.size() - 1];
    showvector(v); // 15

    // removes last element
    v.pop_back();
    showvector(v); // 10 10 10 10 10

    // vector_name.insert (position, val)
    v.insert(v.begin(), 5);
    cout << "\nThe first element is: " << v[0]; // 5

    // vectorname.erase(position) or vectorname.erase(startingposition, endingposition)
    v.erase(v.begin() + 3);
    cout << "\nThe third element is: " << v[3]; // 10

    // erases the vector
    v.clear();
    cout << "\nVector size after erase(): " << v.size();

    // two vector to perform swap
    vector<int> v1 = {2, 3, 42, 32}, v2 = {63, 12, 45, 23};
    showvector(v1);
    showvector(v2);

    // Swaps v1 and v2
    v1.swap(v2);

    cout << "\nAfter Swap";
    showvector(v1);
    showvector(v2);

    /* Methods for Initializing the vectors

    1. vector<data_type> obj{values}
        vector<int> vect{ 10, 20, 30 };

    2. vector<data_type> obj(size,value);
        vector<int> vect(n, 10);  //Create a vector of size n with all values as 10.

    3. vector<data_type> obj;
        obj.push_back(values);

      Method for Initializing 2D vectors

    1. vector <vector<data_type>> obj(vec1_size, vector<data_type> (vec2_size,value));
        vector<vector<int>> vec( n , vector<int> (m, 0));
        We create a 2D vector containing "n" elements each having the value "vector<int> (m, 0)".
        "vector<int> (m, 0)" means a vector having "m" elements each of value "0".
    */

    return 0;
}
/*
Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.
Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.
In vectors, data is inserted at the end.

Certain functions associated with the vector are:

begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin(),cend(),crbegin(),crend() – Returns a constant iterator.

size() – Returns the number of elements in the vector.
capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
resize(n) – Resizes the container so that it contains ‘n’ elements.
empty() – Returns whether the container is empty.

at(g) – Returns a reference to the element at position ‘g’ in the vector
front() – Returns a reference to the first element in the vector
back() – Returns a reference to the last element in the vector

assign() – It assigns new value to the vector elements by replacing old ones
push_back() – It push the elements into a vector from the back
pop_back() – It is used to pop or remove elements from a vector from the back.
insert() – It inserts new elements before the element at the specified position
erase() – It is used to remove elements from a container from the specified position or range.
swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
clear() – It is used to remove all the elements of the vector container

*/