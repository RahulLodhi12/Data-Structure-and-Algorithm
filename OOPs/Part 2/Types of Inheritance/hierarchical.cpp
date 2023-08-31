#include<bits/stdc++.h>
using namespace std;

class Animal{ // Single Base class for Two or more Derived class.
    public:
        int age;
        int weight;

        void sound(){
            cout<<"Speaking.."<<endl;
        }
};

class Dog: public Animal{
    public:
        string breed;

        void bark(){
            cout<<"Barking.."<<endl;
        }

};

class Cat:  public Animal{
    protected:
        string petName;

    public:
        void meow(){
            cout<<"Meow.."<<endl;
        }
};

int main(){

    Dog d1;
    d1.sound();
    d1.bark();

    Cat c1;
    c1.sound();
    c1.meow();

}