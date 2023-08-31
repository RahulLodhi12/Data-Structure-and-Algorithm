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
    protected:
        string breed;

};

int main(){

    Dog d1;
    d1.sound();

}