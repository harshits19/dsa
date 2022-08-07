#include <iostream>
#include <list>
#include <iterator>
using namespace std;
//Lists in C++ STL

void showlist(list<int> &lst)
{
    cout << "List : ";
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
bool even(const int &value) { return (value % 2) == 0; }
int main()
{
    list<int> list1 = {2, 34, 12, 23, 46, 35, 87};
    list<int>::iterator ptr;
    showlist(list1);

    cout << "Front most item in list is : " << list1.front() << endl;
    cout << "Last most item in list is : " << list1.back() << endl;

    // list_name.push_front(dataType value)
    list1.push_front(23);
    list1.push_back(48);
    cout << "Adding 23 and 48 at starting and end of ";
    showlist(list1);

    list1.pop_front();
    list1.pop_back();
    cout << "Removed first and last element of ";
    showlist(list1);

    (list1.empty() == 0) ? cout << "Non Empty List\n" : cout << " Empty List\n";

    // insert(position_of_iter,num_of_ele, value_of_ele)
    ptr = list1.begin();
    list1.insert(ptr, 4, 23);
    //list1.insert(ptr,45); //when no of elements are not specified, then its default value is 1
    // list1.insert(list1.end(), 4, 23);
    cout << "Adding 23 value 4 times in starting of ";
    showlist(list1);

    //list_name.erase(iterator position) or list_name.erase(iterator first, iterator last)
    ptr = list1.begin();     //(ptr->23)
    auto it2 = next(ptr, 5); //shift ptr forward by 5 place (ptr->34)
    list1.erase(ptr, it2);   //erase items between elements 23 and 34, but exclude 34
    cout << "Erasing content of index 1 to 5 of ";
    showlist(list1);

    //list_name.assign(count, value)
    //list1.assign(2, 100); // Assigning the value 100, 2 times
    //showlist(list1); //it recreates the list,deletes previous values

    list1.remove(12);
    cout << "After removing value 12 from the ";
    showlist(list1);

    list1.remove_if(even);
    cout << "After removing all odd index values from the ";
    showlist(list1);

    list1.reverse();
    cout << "Reversed ";
    showlist(list1);
    cout << "Size of List is : " << list1.size() << endl;

    // list_name.resize(int n, value)
    // n : specifies the number of elements upto which the list is needed to be resized.
    // value: This is an optional parameter and if it is specified and the list contains less than n elements then the function will add elements to the list with their value assigned to val.
    list1.resize(6,54);
    cout<<"Resized ";
    showlist(list1);

    list1.sort();
    cout<<"Sorted ";
    showlist(list1);

    list1.unique();
    cout<<"Only unique elements ";
    showlist(list1);

    list <int> l1{2,4,5,6}, l2{6,3,9,1,5,2};
    //l2=l1;
    //This operator is used to assign new contents to the container by replacing the existing contents.
    //It also modifies the size according to the new contents.
    //showlist(l2);

    l1.swap(l2);
    cout<<"Swapped L1 ";
    showlist(l1);

    l1.merge(l2);
    cout<<"Merged L1 and L2 ";
    showlist(l1);


     return 0;
}
/*
Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, list has slow traversal, but once a position has been found, insertion and deletion are quick. Normally, when we say a List, we talk about doubly linked list. For implementing a singly linked list, we use forward list.

Functions used with List:

front() – Returns the value of the first element in the list.
back() – Returns the value of the last element in the list .

push_front(g) – Adds a new element ‘g’ at the beginning of the list .
push_back(g) – Adds a new element ‘g’ at the end of the list.
pop_front() – Removes the first element of the list, and reduces size of the list by 1.
pop_back() – Removes the last element of the list, and reduces size of the list by 1


empty() – Returns whether the list is empty(1) or not(0).
insert() – Inserts new elements in the list before the element at a specified position.
erase() – Removes a single element or a range of elements from the list.
assign() – Assigns new elements to list by replacing current elements and resizes the list. It can also be used to copy elements from one list to another.

remove() – Removes all the elements from the list, which are equal to given element.
remove_if() - Used to remove all the values from the list that correspond true to the predicate or condition given as parameter to the function.
reverse() – Reverses the list.
size() – Returns the number of elements in the list.
resize() – Used to resize a list container.
sort() – Sorts the list in increasing order.
unique() – Removes all duplicate consecutive elements from the list.
clear() – clear() function is used to remove all the elements of the list container, thus making it size 0.
list::operator= – This operator is used to assign new contents to the container by replacing the existing contents.
swap() – This function is used to swap the contents of one list with another list of same type and size.
merge() – Merges two sorted lists into one

list::begin() and list::end() in C++ STL– begin() function returns an iterator pointing to the first element of the list
end()– end() function returns an iterator pointing to the theoretical last element which follows the last element.
list rbegin() and rend() function in C++ STL– rbegin() returns a reverse iterator which points to the last element of the list. rend() returns a reverse iterator which points to the position before the beginning of the list.
list cbegin() and cend() function in C++ STL– cbegin() returns a constant random access iterator which points to the beginning of the list. cend() returns a constant random access iterator which points to the end of the list.
list crbegin() and crend() function in C++ STL– crbegin() returns a constant reverse iterator which points to the last element of the list i.e reversed beginning of container. crend() returns a constant reverse iterator which points to the theoretical element preceding the first element in the list i.e. the reverse end of the list.

*/