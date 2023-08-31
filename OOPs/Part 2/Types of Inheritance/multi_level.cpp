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

class Dog: public Animal{
    public:
        string breed;

};

class Bulldog:  public Dog{
    protected:
        string petName;
};

int main(){

    Bulldog d1;
    d1.sound();

}