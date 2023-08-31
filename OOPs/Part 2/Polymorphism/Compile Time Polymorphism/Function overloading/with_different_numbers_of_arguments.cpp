/*
Function overloading:-
When there are multiple functionsin a class with the same name but different parameters, 
these functions are overloaded. The main advantage of function overloading is it increases 
the readability of the program. Functions can be overloaded by using different numbers of 
arguments and by using different types of arguments.


i) Function overloading with different numbers of arguments:-
In this example, we have created two functions, the first add() performs the addition of the two numbers, 
and the second add() performs the addition of the three numbers. Let’s look at the example below.
*/

#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        // Function with two parameters
        int add(int n1, int n2){
            return n1+n2;
        }

        // Function with three parameters
        int add(int n1, int n2, int n3){
            return n1+n2+n3;
        }
};

int main(){

    A obj;
    cout<<obj.add(3,4)<<endl;
    cout<<obj.add(10,20,30)<<endl;

}