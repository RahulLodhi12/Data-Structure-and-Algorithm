#include<bits/stdc++.h>
using namespace std;

class Person{ // Base class
    protected:
        int age;
	public:
	    string name;
	
		void setData(int age, string name){
			this->age = age;
            this->name = name;
		}
};

class Student: private Person{ // Derived class
	public:
	    int rollno;
	    string course;

        void setInfo(int r, string c){
            this->rollno = r;
            this->course = c;
        }

		void display(){
            cout<<"age: "<<this->age<<endl;
            cout<<"name: "<<this->name<<endl;
            cout<<"rollno: "<<this->rollno<<endl;
            cout<<"course: "<<this->course<<endl;
		}

        void data(){
            this->setData(21,"Rahul");
        }
};

int main(){
	Student s1;
    // s1.setData(21,"Rahul");
    s1.setInfo(89,"Btech");
    s1.data();
    s1.display();

    // cout<<s1.age<<endl;
	
}
/*
Inheritance in C++ an Overview :-
1.Reusability is a very important feature of OOPs
2.In C++ we can reuse a class and add additional features to it
3.Reusing classes saves time and money
4.Reusing already tested and debugged classes will save a lot of effort of developing and debugging the same thing again

What is Inheritance in C++? :-
1.The concept of reusability in C++ is supported using inheritance
2.We can reuse the properties of an existing class by inheriting it
3.The existing class is called a base class
4.The new class which is inherited from the base class is called a derived class
5.Reusing classes saves time and money
6.There are different types of inheritance in C++

-> derived class (child) - the class that inherits from another class
-> base class (parent) - the class being inherited from

** Mode of Inheritance **
    Base class               Child class  
    (Access modifier)    (Mode of inheritance)
    public                      public         ->   public
    public                      private        ->   private
    public                      protected      ->   protected

    protected                   public         ->   protected
    protected                   protected      ->   protected
    protected                   private        ->   private

    private                     public         ->   N.A(Not Accessible)
    private                     private        ->   N.A       
    private                     protected      ->   N.A

Note: Private memeber of any class can not be inherited.
Note: The third specifier, protected, is similar to private, but it can also be accessed in the inherited(derived) class.


Types of Inheritance in C++ :-
1.Single Inheritance
2.Multiple Inheritance
3.Hierarchical Inheritance
4.Multilevel Inheritance
5.Hybrid Inheritance
*/
