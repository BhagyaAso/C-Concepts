/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Base{
    public:
    virtual void print(){
        cout<<"print Base class \n";
    }
    
    void show(){
        cout<<"show Base class \n";
    }
};

class Derived : public Base{
   // private: ?? same output we will get as public
   public:
    void print(){
        cout<<"print Derived class \n";
    }
    void show(){
        cout<<"show Derived class \n";
    }
};

int main(){
    Base* bptr;
    Derived dptr;
    bptr = &dptr;
    // Virtual function, binded at runtime
    bptr -> print();
    // Non-virtual function, binded at compile time
    bptr -> show();
    return 0;
}