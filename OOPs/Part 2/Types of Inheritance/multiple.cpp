#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
        int age;
        int weight;

        void sound(){
            cout<<"Speaking.."<<endl;
        }
};

class Dog{
    public:
        string breed;

        void bark(){
            cout<<"Barking.."<<endl;
        }

};

class Bulldog:  public Animal, public Dog{
    protected:
        string petName;
};

int main(){

    Bulldog d1;
    d1.sound();
    d1.bark();

}