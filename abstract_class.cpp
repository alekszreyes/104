#include <iostream>

using namespace std;

class Abstract {
public:
    // pure virtual
    virtual void print() = 0;
};

class Child : Abstract {
public:

    // compiler enforces you to implement this
    void print() { cout << "Implemented" << endl; }
};

int main(void)
{
    Child child;
    child.print();
}
