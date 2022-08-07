#include <iostream>
#include <map>
#include <iterator>
using namespace std;
// Maps in STL C++
// The maps stored the data in ordered way
// The map is based on the self balancing red black tree
// The items are ordered wrt key
// Map stores only distinct values
void showmap(map<int, char> &maps)
{
    for (auto ptr = maps.begin(); ptr != maps.end(); ptr++)
    {
        // cout<<(*ptr).first<<" "<<(*ptr).second<<endl;
        cout << ptr->first << " " << ptr->second << endl;
    }
}

void showmap(map<string, int> &maps)
{
    for (auto ptr = maps.begin(); ptr != maps.end(); ptr++)
    {
        cout << ptr->first << " " << ptr->second << endl;
    }
}
int main()
{

    // map <data_type_of_key,   data_type_of_value>  variable_name;
    map<int, char> alp;
    // This map will be sorted by order of numbers
    alp = {{1, 'a'}, {9, 'i'}, {5, 'e'}};
    /*  map_name[key] = value; Alternate Way*/
    alp[4] = 'd';
    alp[6] = 'f';
    alp[7] = 'g';
    cout << "Key - Value" << endl;
    showmap(alp);

    /* for (auto it = alp.find(4); it != alp.end(); it++) //It will print all the elements after key=4 to end including key=4
        cout << (*it).first << " " << (*it).second << " " << endl; */

    // This map will be sorted by the order of alphabets in string
    map<string, int> names;
    // map<string, int>::iterator it;
    names["Atul"] = 58;    // we can insert or update the value with [] brackets
    names.at("Atul") = 76; // Alternately we can use at operator
    // the difference between [] brackets and at-operator is that when we try to access any unmapped value, the [] bracket will assign that value but at-operator will throw an exception
    names.insert(pair<string, int>("Rohan", 40)); // AlterWay of inserting
    names.insert({"Lola", 74});
    cout << "Key - Value" << endl;
    showmap(names);

    cout << alp[5] << endl;
    // if we pass any key which is not present in map, then that key is automatically added into the map with some default value, in case of integer value=0;
    alp[8]; // 8 key is added in the map - alp
    showmap(alp);

    // searching a key in a map
    // the find(key_value) operator searches for the key in map and if key found then returns the iterator pointing to that key else returns iterator to the end of map
    if (names.find("Atul") != names.end())
    {
        auto it = names.find("Atul");
        cout << "Found " << (*it).first << " at " << (*it).second << endl;
    }
    else
        cout << "Not Found" << endl;

    // assigning the elements from map2 to map3
    // map<string, int> map3(map2.begin(), map2.end());
    // showmap(map3);
    return 0;
}
/*
Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.

find(key) -  returns the iterator pointing to the searched key else end of map
count(key) -  returns 1 if key is present , and 0 if key is not present
begin() – Returns an iterator to the first element in the map
end() – Returns an iterator to the theoretical element that follows last element in the map
size() – Returns the number of elements in the map
empty() – Returns whether the map is empty
pair insert(keyvalue, mapvalue) – Adds a new element to the map
erase(iterator position) – Removes the element at the position pointed by the iterator
erase(const g)– Removes the key value ‘g’ from the map
clear() – Removes all the elements from the map

*/