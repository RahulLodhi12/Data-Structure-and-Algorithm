/*
Default Arguments:
A default argument is a value provided in a function declaration automatically assigned
by the compiler if the function’s caller doesn’t provide a value for the argument
with a default value. However, if arguments are passed while calling the function,
the default arguments are ignored.


Example: A function with default arguments can be called with 2  or 3 or 4 arguments.
*/
#include <iostream>
using namespace std;

int add(int x, int y, int z = 0, int w = 0) //function declaration
{
    return (x + y + z + w);
}
int main()
{
    cout << add(10, 20) << endl;
    cout << add(10, 20, 30) << endl;
    cout << add(10, 20, 30, 40) << endl;
    return 0;
}