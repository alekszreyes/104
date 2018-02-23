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

void ssort(vector<int> mylist)
{
    for(int i = 0, len = (int)mylist.size(); i < len - 1; i++){
        
        // min begins as the first element
        int min = i;
        
        for(int j = i + 1; j < (int) mylist.size(); j++){
        
            // if min is smaller than current value, save new min
            if(mylist[j] < mylist[min]) {
                min = j;
            }
            
        }
        // swap i and min
        int temp = mylist[min];
        mylist[min] = mylist[i];
        mylist[i] = temp;
        
        
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
    
    cout << "Selection sorting: " << endl;
    ssort(v);
}
