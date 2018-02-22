# CS 104 Midterm Review

Sometimes, the best way to understand a concept
is seeing minimalistic snippets of code. Feel free
to clone, pull or contribute to this.

Also, notice that there are c++ examples that you can
browse, compile and execute.

## Friend functions
Used when you need to access private data
from outside your class

```c
#include <iostream>

using namespace std;

class Book {
public:
    Book(string name): _name(name) {}
    ~Book() {}

    void getName() { cout << _name << endl; }

    // friend declaration
    friend void appendName(Book &b);

private:
    string _name;

};

/***
* notice that it is able to access the private data
**/
void appendName(Book &b) {
    b._name = b._name + " written by Alex ";
}

int main(void)
{
    Book b("Moby Dick");
    b.getName(); // prints Moby Dick

    appendName(b);
    b.getName(); // prints Moby Dick written by Alex
}
```

## Polymorphism
Sometimes you can have different classes that have the
same function but each function does different things.

You can take a pointer, assign it to one of the objects,
call the function of that object, and then repeat for a
different object.

Here is a simple example.

```c
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
```
