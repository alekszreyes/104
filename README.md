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
## Deep copy

Copies, by default, are shallow. That is okay
when you are working on the stack, but when you
are working with dynamic memory, what you really
copy is a pointer. This can lead to segfault or
other problems when different objects are pointing
to the same address.

The solution is deep copy. However, it is something you
have to write yourself. The rule is to include these three
things.

1. Constructor
2. Destructor
3. Operator

Here is a simple example

```c
#include <iostream>

using namespace std;

class Student {
    public:
        Student(int id, string name):
            _id(id), _name(name) {}
        int _id;
        string _name;

    Student* deepCopy() {
        return new Student(_id, _name);
    }
    Student& operator=(const Student &rhs) {
        if( this == &rhs ) return *this;

        this->_id = rhs._id;
        this->_name = rhs._name;

        return *this;
    }
};

int main(void) {

    // object
    Student* student = new Student(1, "alex");
    Student* cp = student->deepCopy();

    cp->_name = "sergio";

    cout << "st: " << student->_name << endl;
    cout << "cp: " << cp->_name << endl;

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
##Sorting Algorithms


```c
│   ├── print_all.cpp
#include <iostream>

using namespace std;

/*** MAIN FUNCTION ***/
int main(int argc, const char * argv[]) {

    int a[] = {4, 3, 1, 5, 9};
    for(int i = 1; i < 4; i++)
    {
        // keep track of where we are
        int element = a[i];
        int j = i;

        // while within bounds and previous element is greater than current
        while(j > 0 && a[j - 1] > element)
        {
            // move one space
            a[j] = a[j - 1];
            j -= 1;
        }
        // save element in new position
        a[j] = element;
    }
    for(int i = 0; i < 4; i++)
    {
        cout << "element: " << a[i] << endl;
    }
}
```

### Selection Sort

This is one of the types of sorting algorithms

```c
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    static const int a[] = { 13, 9, 6, 3, 15, 2, 21, 4, 16, 8, 11 };
    vector<int> v(a, a + sizeof(a)/sizeof(a[0]));


    // for each element in vector
    for(int i = 0, len = (int)v.size(); i < len; i++) {

        // let's begin with the starting value
        int min = i;

        // compare with the rest of the array
        for(int j = i; j < len; j++) {

            // if find a smaller one, save as the new min
            if(v.at(min) > v.at(j)) {
                min = j;
            }
        }

        // when finish iterating, save the min
        if(min != i) {
            swap(v.at(i), v.at(min));
            cout << v.at(i) << endl;
        }
    }
}
```
