#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
// Algorithms in C++ STL
void showvector(vector<int> &vtr)
{
    cout << "Vector :";
    for (auto it = vtr.begin(); it != vtr.end(); it++)
        cout << *it << " ";
    cout << endl;
}
int main()
{
    vector<int> vec{92, 53, 53, 34, 73, 21};
    vector<int>::iterator it;

    it = vec.begin();
    sort(it, it + 5);
    // sort(it,it+5,greater<int>()); //sorting array in descending order
    showvector(vec);
    reverse(it, it + 5);
    showvector(vec);
    cout << "Max Element : " << *max_element(it, it + 5) << endl;
    cout << "Min Element : " << *min_element(it, it + 5) << endl;

    cout << "No of 21's in vector : " << count(it, it + 5, 21) << endl;
    cout << "Search 36 in vector : " << binary_search(it, it + 5, 36) << endl; // returns 1 if present and 0 if absent

    return 0;
}
/*
Algorithms
The header algorithm defines a collection of functions especially designed to be used on ranges of elements.They act on containers and provide means for various operations for the contents of the containers.

sort(first_iterator, last_iterator) – To sort the given vector.
reverse(first_iterator, last_iterator) – To reverse a vector.
*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
*min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements
count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted vector or not. returns true or false
find(first_iterator, last_iterator, x) – Returns an iterator to the first occurence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector.
lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.
upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’.

*/