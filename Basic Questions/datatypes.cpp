/*
Data Type	    Size (in bytes)	        Range
short int	        2	                -32,768 to 32,767
unsigned short int	2	                0 to 65,535
unsigned int	    4	                0 to 4,294,967,295
int	                4	                -2,147,483,648 to 2,147,483,647
long int	        4	                -2,147,483,648 to 2,147,483,647
unsigned long int	4	                0 to 4,294,967,295
long long int	    8	                -(2^63) to (2^63)-1
unsigned long long int	8	            0 to 18,446,744,073,709,551,615
signed char	        1	                -128 to 127
unsigned char	    1	                0 to 255
float	            4
double	            8
long double	        12
wchar_t	2 or 4	1 wide character
*/
#include <iostream>
using namespace std;

int main()
{
    cout << "Size of char : " << sizeof(char)
         << " byte" << endl;
    cout << "Size of int : " << sizeof(int)
         << " bytes" << endl;
    cout << "Size of short int : " << sizeof(short int)
         << " bytes" << endl;
    cout << "Size of long int : " << sizeof(long int)
         << " bytes" << endl;
    cout << "Size of signed long int : " << sizeof(signed long int)
         << " bytes" << endl;
    cout << "Size of unsigned long int : " << sizeof(unsigned long int)
         << " bytes" << endl;
    cout << "Size of float : " << sizeof(float)
         << " bytes" << endl;
    cout << "Size of double : " << sizeof(double)
         << " bytes" << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t)
         << " bytes" << endl;

    return 0;
}
