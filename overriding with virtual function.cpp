
//Another Approach of function overriding with virtual function//
#include <iostream>
using namespace std;

class Base{
public:
virtual void print(){cout<<"Print Base Class \n";} 
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
    Base* b;
    Derived d;
    b = &d;
    b->print();
    d.show();
    return 0;
}

/*
o/p

Print Derived Class 
Show Derived Class 
Show Base Class 
*/