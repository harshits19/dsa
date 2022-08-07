#include <iostream>
#include <set>
using namespace std;

/* The set stores the elements in sorted order.
A set is based on the self balancing red black tree
All the elements in a set have unique values.
The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
Sets follow the Binary search tree implementation.
The values in a set are unindexed. */

int main()
{
    set<int> s; // It will sort data in ascending order
    /* set<int, greater<int>> s; it will sort the data in descending order */
    s.insert(20);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(10);    // if we try to add the duplicate value then set ignores it
    for (auto x : s) // traversing shorthand
        cout << x << " ";
    cout << endl;
    for (auto it = s.begin(); it != s.end(); it++) // here it-> iterator
        cout << (*it) << " ";
    cout << endl;

    return 0;
}
/*
Some Basic Functions Associated with Set:

begin() – Returns an iterator to the first element in the set.
end() – Returns an iterator to the theoretical element that follows the last element in the set.
size() – Returns the number of elements in the set.
max_size() – Returns the maximum number of elements that the set can hold.
empty() – Returns whether the set is empty.
erase(iterator position) - Removes the element at the position pointed by the iterator.
erase(const g) - Removes the value ‘g’ from the set.
clear() - Removes all the elements from the set.
find(const g) - Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
count(const g) - Returns 1 or 0 based on the element ‘g’ is present in the set or not.
lower_bound(const g) - Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.
upper_bound(const g) - Returns an iterator to the first element that will go after the element ‘g’ in the set.
swap() - This function is used to exchange the contents of two sets but the sets must be of the same type, although sizes may differ.
operator= - The ‘=’ is an operator in C++ STL which copies (or moves) a set to another set and set::operator= is the corresponding operator function.

 */