#include<bits/stdc++.h>
using namespace std;


class Employee{
    //Data member
    private:
        int salary;
    
    public:
        void setSalary(int s){
            salary = s;
        }

        int getSalary(){
            return salary;
        }
};


int main(){
    Employee e1; // static memory allocation

    e1.setSalary(23456); // setter -> assign, modify, apply condn.
    cout<<"Salary: "<<e1.getSalary()<<endl; // getter -> print(output), fetch, read

}
/*
If you want others to read or modify the value of a private member, you can provide public "getter" and "setter" methods.
But the "getter" and "setter" methods must be public member.
*/