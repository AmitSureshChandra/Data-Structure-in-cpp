#include<iostream>
#define size 10
using namespace std;

int* a = new int[size];

int moduloHash(int t) { return t % size; }

int search(int target) { return a[moduloHash(target)]; }

void printHash() { 
    for(int i=0; i< size; i++) cout<< "key : " << i << "\t" << "value : " << a[i]<< endl; 
}

int main() {
    for(int i=0; i< size; i++) a[i] = -1;   // init hash with -1
    int n; // size of array
    cout<< "Enter the size of array : ";
    cin >>n;
    
    cout<< "Enter array elements " << endl;
    for(int i=0; i< n;){
        int temp;
        cin>> temp;
        int hash = moduloHash(temp); // calculate hash for temp .. if already found then reject
        if(a[hash] != -1) cout<<"Collision : Unable to insert "<< temp<< endl;
        else {
            a[hash] = temp;
            i++; // increment only if insert is successful
        }
    }
    cout<< "~~~ Hash Table ~~~"<< endl;
    printHash();
    int t;
    cout<<"Enter element to search : ";
    cin >> t;
    int val = search(t);
    if(val == t) cout<<"Found";
    else cout<<"Not Found";

    return 0;
}