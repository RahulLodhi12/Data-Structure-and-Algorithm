#include<bits/stdc++.h>
using namespace std;

class Student{
    //properties(Data members)
    int marks;
};


int main(){

    Student s1; //creation of object named s1
//  Student(class) s1(object) similar to int a, char ch, string name;
//  means that Class is just a user-defined data type.

//  When we create an object(s1), then an instance is created in memory, means that 
//  memory block is reserved and allocated to object s1.(as we don't assign a value during object creation, 
//  a garage value(of type int) is assigned to marks variable)

    cout<<"size: "<<sizeof(s1);

}