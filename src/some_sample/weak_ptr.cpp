#include <bits/stdc++.h>
using namespace std;
class B;
class A{
    public:
        A()  {cout << "A Constructor" << endl;}
        ~A() {cout << "A Destructor" << endl;}
        weak_ptr<B> spb;
};
class B{
    public:
    B() { cout << "B Constructor" << endl;}
    ~B() {cout << "B Destuctor" << endl;}
    weak_ptr<A> spa;
};
int32_t main() {
    shared_ptr<A> pa = make_shared<A> ();
    shared_ptr<B> pb = make_shared<B> ();
    pa->spb = pb;
    pb->spa = pa;
    return 0;
}