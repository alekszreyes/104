#include <iostream>

using namespace std;

int fib(int n) {
    
    if(n == 1 || n == 0) return n;
    
    return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    // print the first 15 number of the fibonacci series
    for(int i = 0; i < 15; i++) {
        cout << fib(i) << endl;
    }
}
