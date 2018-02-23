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

void isort(vector<int> mylist) {
    
    for(int i = 1; i < (int) mylist.size(); i++){
        
        int val = mylist[i];
        int hole = i;
    
        while(hole > 0 && val < mylist[hole - 1]) {
            
            mylist[hole] = mylist[hole - 1];
            hole--;
        }
        mylist[hole] = val;
        printVector(mylist);
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
    
    cout << "Insertion sorting: " << endl;
    isort(v);
}
