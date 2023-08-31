/*
ii) Function overloading with different types of arguments: 
In this example, we have created two add() functions with different data types. 
The first add() takes two integer arguments and the second add() takes two double arguments.
*/

#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        // Function with two integer parameters
        int add(int n1, int n2){
            return n1+n2;
        }

        // Function with two double parameters
        double add(double n1, double n2){
            return n1+n2;
        }
};

int main(){

    A obj;
    cout<<obj.add(3,4)<<endl;

    cout<<obj.add(10.23,20.72)<<endl;

}