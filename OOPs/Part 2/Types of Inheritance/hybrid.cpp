//combination of more than one type of inheritance, like hierarchical and multiple.
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

class Bulldog{
    public:
        string petName;

        void bite(){
            cout<<"Biting.."<<endl;
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

class Dog: public Animal, public Bulldog{
    public:
        string breed;

        void bark(){
            cout<<"Barking.."<<endl;
        }
};

int main(){

    Cat c1;
    c1.sound();
    c1.meow();

    Dog d1;
    d1.sound();
    d1.bark();
    d1.bite();

}