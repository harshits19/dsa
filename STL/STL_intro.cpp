#include <iostream>
using namespace std;

//STL in C++
class A
{
public:
    int vari[5];
    void setmarks(int *cm)
    {
        for (int i = 0; i < 5; i++)
            vari[i] = cm[i];
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
            cout << vari[i] << " ";
    }
};
int main()
{
    int marks[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }
     A a;
     a.setmarks(marks);
     a.display();

    return 0;
}

/*
The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc.
STL has four components:
1. Algorithms
2. Containers
3. Functions
4. Iterators

1. Algorithms
The header algorithm defines a collection of functions especially designed to be used on ranges of elements.They act on containers and provide means for various operations for the contents of the containers.
1. Algorithm
2. Sorting
3. Searching
4. Important STL Algorithms
5. Useful Array algorithms
6. Partition Operations

2. Containers 
Containers or container classes store objects and data. 

(a). Sequence Containers: implement data structures which can be accessed in a sequential manner.
1. vector
2. list
3. deque
4. arrays
5. forward_list( Introduced in C++11)
(b). Container Adaptors : provide a different interface for sequential containers.
1. queue
2. priority_queue
3. stack
(c). Associative Containers : implement sorted data structures that can be quickly searched (O(log n) complexity).
1. set
2. multiset
3. map
4. multimap

3. Functions
The STL includes classes that overload the function call operator. Instances of such classes are called function objects or functors. Functors allow the working of the associated function to be customized with the help of parameters to be passed.

4. Iterators
As the name suggests, iterators are used for working upon a sequence of values. They are the major feature that allow generality in STL.

*/