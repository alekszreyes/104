#include <iostream>

using namespace std;

class Shape {
public:
    Shape()     {}
    virtual ~Shape()    {}
    virtual void print(){ p( "print shape" );}
    
protected:
    void p(string s) {cout << s << endl;}

};


class Rectangle : public Shape {
public:
    Rectangle() {}
    ~Rectangle(){}
    
    void print() { p("print rectangle"); }
    
};

int main(void)
{
    
    Rectangle* s = new Rectangle();
//    s->print(); // print rectangle called
    
    Shape* t = new Shape();
//    t->print(); // print shape
    
    // pointer to iterate
    Shape* u;
    u = s;
    u->print(); // print rectangle
    
    u = t;
    u->print(); // print shape
    
    
    delete s;
    delete t;
}
