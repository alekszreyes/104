# CS 104 Midterm Review

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


