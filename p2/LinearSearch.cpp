#include<iostream>
using namespace std;

int linearSearch(int* a, int n, int target) {
    for(int i=0; i< n; i++)if(a[i] == target) return i;
    return -1;
}

int main() {
    // size of array
    int n;
    cout<< "Enter the size of array : ";
    cin >>n;
    int* a = new int[n];
    cout<< "Enter array elements " << endl;
    for(int i=0; i< n; i++)cin>> a[i];
    
    int t;
    cout<<"Enter element to search : ";
    cin >> t;

    int pos = linearSearch(a, n, t);
    if(pos == -1) cout<<"Not Found";
    else cout<<"Found at "<<(pos + 1);

    return 0;
}