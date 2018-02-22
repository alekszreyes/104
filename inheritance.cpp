#include <iostream>

using namespace std;

class Parent {
public:
    
    void playFunction() {
        
        // from here I have access to everything of parent
        cout << _public + _protected + _private << endl;
    }
    
    string _public = "public ";

protected:
    string _protected = "protected ";
    
private:
    string _private = "private ";
};

class Child : private Parent {

public:
    // from here I only have access to _public and _private
    void play() {
        cout << _public + _protected << endl;
        
        // but i do not have access to _private
        // cout << _private; // compiler error
    }
    
};

int main(void)
{
    Parent parent;
    parent.playFunction();
    
    cout << parent._public << endl;
    
    // but i cannot invoke parent._protected or parent._private
    
    Child child;
    child.play();
}
