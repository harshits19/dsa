#include <iostream>
#include <iterator> // for iterators
#include <vector>   // for vectors

using namespace std;

int main()
{
    vector<int> ar = {1, 2, 3, 4, 5};

    // Declaring iterator to a vector
    vector<int>::iterator ptr;

    // Displaying vector elements using begin() and end()
    cout << "The vector elements are : ";
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";

    // Using advance() to set position of iterator
    ptr = ar.begin(); // set iterator ptr to starting of vector
    cout << "\nPosition of Iterator before advance() : " << *ptr << endl;
    advance(ptr, 3); // it will move pointer 3 index forward
    cout << "Position of Iterator after advance() : " << *ptr << endl;

    // Using next() and prev()
    ptr = ar.begin();     // Set iterator ptr to starting of vector
    auto it1 = next(ptr); // Using next() to return new iterator
    //  auto it1 = next(ptr,2); // Shifts the position of iterator by 2 places
    cout << "The position of new iterator using next() is : ";
    cout << *it1 << " " << endl;
    ptr = ar.end();          // Set iterator ptr to ending of vector
    auto it2 = prev(ptr, 2); // using auto so that it2 can store the iterator value
    cout << "The position of new iterator using prev() is : ";
    cout << *it2 << " " << endl;

    // inserting vector ar1 into another vector ar
    vector<int> ar1 = {10, 20, 30};
    ptr = ar.begin();
    advance(ptr, 2);
    copy(ar1.begin(), ar1.end(), inserter(ar, ptr));
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";

    ;
    return 0;
}
/*
Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequence of numbers, characters etc. They reduce the complexity and execution time of program.

1. begin() :- This function is used to return the beginning position of the container.
2. end() :- This function is used to return the after end position of the container.
3. advance() :- This function is used to increment the iterator position till the specified number mentioned in its arguments.
6. inserter() :- This function is used to insert the elements at any position in the container. It accepts 2 arguments, the container and iterator to position where the elements have to be inserted.
*/