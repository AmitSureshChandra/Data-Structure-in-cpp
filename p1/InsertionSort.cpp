#include<iostream>

using namespace std;

void swap(int* a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void print(int* a, int n) {
    for(int i=0; i< n; i++) cout<<a[i]<< " ";
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

    // insertion sort
    for(int i=1; i< n; i++) {
        for(int j=0; j< i; j++) if(a[i] < a[j]) swap(a, i, j); 
    }
    cout<<"After Sorting"<< endl;
    print(a, n);
    return 0;
}