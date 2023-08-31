/*
Operator Overloading:-
C++ also provides optionsto overload operators. For example, we can make the operator (‘+’) for the string class
to concatenate two strings. We know that this is the addition operator whose task is to add two operands. 
A single operator, ‘+,’ when placed between integer operands, adds them and concatenates them when placed between 
string operands. 

Points to remember while overloading an operator:-
●It can be used only for user-defined operators(objects, structures)but cannot be used for 
in-built operators(int, char, float, etc.). 
●Operators = and & are already overloaded in C++, so we can avoid overloading them. 
●Precedence and associativity of operators remain intact.
*/

#include<bits/stdc++.h>
using namespace std;

class temp{
    public:
        int num;

        void operator + (temp &obj){ // + is binary operator
            int val1 = this->num;
            int val2 = obj.num;
            cout<<"Output: "<<val2-val1<<endl;
        }

        void operator () (){ // () is unary operator
            cout<<"Hello World"<<endl;
        }
};

int main(){

    temp t1,t2;
    t1.num = 4;
    t2.num = 7;

    t1 + t2; // operator overloading

    t1 ();
}