#include <iostream>
#include <sstream>

using namespace std;



string operator+(string s, char c) {
    
    // we use string stream
    stringstream ss;
    
    // from char to string stream
    ss << c;
    
    // here we save the char to string
    string c_as_string;
    ss >> c_as_string;
    
    // we append the former char and return
    s.append(c_as_string);
    return s;
}

int main(void)
{
    // overloading
    string coo = "coo";
    char l = 'l';
    
	// calls overload and prints "cool"
    cout << coo + l << endl;
}
