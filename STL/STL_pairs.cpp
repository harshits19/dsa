#include <iostream>
#include <utility> //header file for using pairs
using namespace std;

// Pair is used to combine together two values that may be of different data types. Pair provides a way to store two heterogeneous objects as a single unit
// The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
// Pair can be assigned, copied, and compared.
// The array of objects allocated in a map or hash_map is of type ‘pair’ by default in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.

int main() {
    pair<int, char> PAIR1;
    PAIR1.first = 100;
    PAIR1.second = 'G';

    // Different ways to initialize pair :
    pair<int, int> g1;          // default
    pair<int, char> g2(1, 'a'); // initialized,  different data type
    pair<int, int> g3(1, 10);   // initialized,  same data type
    pair<int, int> g4(g3);      // copy of g3

    g3 = make_pair(1, 8); // This template function allows to create a value pair without writing the types explicitly.
    g4 = {1, 9};          // Another valid syntax
    g3.swap(g4);          // This function swaps the contents of one pair object with the contents of another pair object. The pairs must be of the same type.

    pair<string, int> g5("Quiz", 3);
    g5 = make_pair(string("Geeks"), 1);

    return 0;
}