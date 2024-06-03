/*
Function overriding in C++ is termed as the redefinition of base class function in its derived class with the same signature 
i.e. return type and parameters. It falls under the category of Runtime Polymorphism.
    
	It falls under Runtime Polymorphism
	A function cannot be overridden multiple times as it is resolved at Run time 
	Cannot be executed without inheritance
	They are of different scopes.
*/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Base{
public:
void print(){cout<<"Print Base Class \n";} 
void show(){cout<<"Show Base Class \n";}
//void show(){cout<<"Show Base Class \n";} cannot be overload againsame functionin same class
};

class Derived : public Base{
public:
void print(){cout<<"Print Derived Class \n";}
void show(){cout<<"Show Derived Class \n";
    Base::show();
}
};

int main()
{
    Derived d;
    d.show();
    return 0;
}
/*
o/p

Show Derived Class 
Show Base Class 
*/


