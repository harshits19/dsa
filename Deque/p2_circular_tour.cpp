#include <iostream>
using namespace std;

int naive_method(int *gas, int *dist, int n) // n=no of city
{
    for (int start = 0; start < n; start++) // start, is position from which district the journey starts
    {
        int curr_gas = 0;
        int end = start; // take another variable which is equal to starting city
        while (1)
        {
            curr_gas = curr_gas + (gas[end] - dist[end]); // remaining gas(i) = gas unit(i) - distance unit(i)
            if (curr_gas < 0)
                break;           // if total gas is less than distance then man couldnot travel to next city hence break
            end = (end + 1) % n; // changing city from (i) to (i + 1), modulo(n) used because we use circular array for tarvelling back from 4->1
            if (end == start)    // when the man come back to starting city
                return (start + 1);
        }
    }
    return -1;
}

int main()
{
    int gas[4] = {4, 8, 7, 4};
    int dist[4] = {6, 5, 3, 5};

    int n = sizeof(dist) / sizeof(int);
    cout << naive_method(gas, dist, n);
    return 0;
}

/*Explanation
city = 1,2,3,4
distance: 1->2 = 6 , 2->3 = 5, 3->4 = 6, 4->1 = 5
gas =     1->2 = 4 , 2->3 = 8, 3->4 = 7, 4->1 = 4

                    6
            (1)-------------(2)
            |                |
          5 |                |5
            |                |
            |                |
            (4)-------------(3)
                    3

case 1: starting city : 1 (not possible) dist = 6 , gas = 4 (dist>gas)
case 2: starting city : 2

        City            2           3           4           1
        total gas       8           7+3         4+4         4+3         total gas = gas given + remaining gas after use
        used gas        5           6           5           6           used gas = distance units
        current gas     3           4           3           2           current gas = total gas - used gas


*/