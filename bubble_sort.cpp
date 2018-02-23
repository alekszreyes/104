#include <iostream>
#include <vector>

using namespace std;

// just a helper function to print the vector
void printVector(vector<int> v) {
    for(int i = 0, len = (int) v.size(); i < len; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// bubble sorting
void bsort(vector<int> mylist) {
    
    for(int i = (int) mylist.size() - 1; i > 0; i--) {
        
        for(int j = 0; j < i; j++) {
            
            // compares with neighbor
            if( mylist[j] > mylist[j + 1] ) {
                
                // swap j and j + 1 if j + 1 is bigger
                int temp = mylist[j];
                mylist[j] = mylist[j + 1];
                mylist[j + 1] = temp;
            }
            printVector(mylist);
        }
    }
}

int main(void)
{
    // create and populate vector
    vector<int> v;
    int array[] = {7, 3, 8, 6, 5, 1};
    v.insert(v.end(), array, array+6);
    
    // printing vector
    cout << "Printing vector: " << endl;
    printVector(v);
    
    cout << "Bubble sorting: " << endl;
    bsort(v);
}
