/*
Explanation: Initially, we create a pointer of the type base class and initialize it 
with the address of the derived class object. When we create an object of the derived class, 
the compiler creates a pointer as a data member of the class containing the address of VTABLE of the derived class.

A similar concept of Late and Early Binding is used as in the above example. 
For the fun_1() function call, the base class version of the function is called, 
fun_2() is overridden in the derived class so the derived class version is called, 
fun_3() is not overridden in the derived class and is a virtual function so the base class version is called, 
similarly fun_4() is not overridden so base class version is called.

Working of Virtual Functions (concept of VTABLE and VPTR)

As discussed here, if a class contains a virtual function then the compiler itself does two things.
If an object of that class is created then a virtual pointer (VPTR) is inserted as a data member of the class to point to the VTABLE of that class. 
For each new object created, a new virtual pointer is inserted as a data member of that class.
Irrespective of whether the object is created or not, the class contains as a member a static array of 
function pointers called VTABLE. Cells of this table store the address of each virtual function contained in that class.

Vtable is separete for per class: eg base class and derived class has different vtable
For each new object: new vptr is inserted as data member in taht calss.
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
   void fun1(){cout<<"Base fun1 \n";}
   virtual void fun2(){cout<<"Base fun2 \n";}
   virtual void fun3(){cout<<"Base fun3 \n";}
   virtual void fun4(){cout<<"Base fun4 \n";}
};

class Derived : public Base{
public:
   void fun1(){cout<<"Derived fun1 \n";}
   void fun2(){cout<<"Derived fun2 \n";}
   void fun4(int x){cout<<"Derived fun4 \n";}
};

int main(){
    Base* bptr;
    Derived dptr;
    bptr = &dptr;
  
    bptr -> fun1();
  
    bptr -> fun2();
    bptr -> fun3();
    bptr -> fun4();
    return 0;
}
/*
0/p

Base fun1
Derived fun2 
Base fun3 
Base fun4 
*/