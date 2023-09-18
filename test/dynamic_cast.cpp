// dynamic_cast_example.cpp
// compile with: /c /GR
#include <iostream>
using namespace std;

class A {
public:
    virtual void f() { cout << "This is A" << endl; }
};

class B : public A {
public:
    void f() { cout << "This is B" << endl; }
};

class C : public A {
public:
    void f() { cout << "This is C" << endl; }
};

class D : public B, public C {
public:
    void f() { cout << "This is D" << endl; }
};

int main() {
    // upcasting, implicit conversion, no need for dynamic_cast
    A* pa = new B;
    pa->f(); // output: This is B

    // downcasting, need dynamic_cast, may fail at runtime
    B* pb = dynamic_cast<B*>(pa); // ok, pa actually points to a B object
    if (pb) {
        pb->f(); // output: This is B
    }
    C* pc = dynamic_cast<C*>(pa); // fail, pa does not point to a C object
    if (pc) {
        pc->f();
    } else {
        cout << "Invalid conversion" << endl; // output: Invalid conversion
    }

    // cross-casting, need dynamic_cast, may fail at runtime
    D* pd = new D;
    /*
    A* pa2 = dynamic_cast<A*>(pd); // ambiguous, need to specify which base class
    // A* pa2 = dynamic_cast<B*>(pd); // ok, unambiguous
    // A* pa2 = dynamic_cast<C*>(pd); // ok, unambiguous
    B* pb2 = dynamic_cast<B*>(pa2); // ok, pa2 points to the B subobject of pd
    C* pc2 = dynamic_cast<C*>(pa2); // fail, pa2 does not point to the C subobject of pd

    */
   return 0 ; 
}
