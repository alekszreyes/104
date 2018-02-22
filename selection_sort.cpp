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
