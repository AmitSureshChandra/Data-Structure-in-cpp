#include<iostream>

using namespace std;

void swap(int* a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int main() {

    // size of array
    int n;

    cout<< "Enter the size of array : ";
    cin >>n;

    int* a = new int[n];

    cout<< "Enter array elements " << endl;

    for(int i=0; i< n; i++){
        cin>> a[i];
    }

    // bubble sort

    for(int i=0; i< n-1; i++) {
        for(int j=i+1; j< n; j++) {
            if(a[i] > a[j]) swap(a, i, j);
        }
    }
    
    cout<<"After Sorting"<< endl;
    for(int i=0; i< n; i++){
        cout<<a[i]<< " ";
    }

    return 0;
}