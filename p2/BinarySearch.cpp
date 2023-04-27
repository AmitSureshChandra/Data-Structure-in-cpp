#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int* a, int n, int target) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(a[mid] == target) return mid;
        if(a[mid] > target)r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main() {
    // size of array
    int n;
    cout<< "Enter the size of array : ";
    cin >>n;
    int* a = new int[n];
    cout<< "Enter array elements " << endl;
    for(int i=0; i< n; i++) cin>> a[i];
    int t;
    cout<<"Enter element to search : ";
    cin >> t;
    // sort if not sorted
    sort(a, a + n);
    cout<<"sorted array"<< endl;
    for(int i=0; i< n; i++)cout<<a[i]<< " ";
    cout<<endl;
    int pos = binarySearch(a, n, t);
    if(pos == -1) cout<<"Not Found";
    else cout<<"Found at "<<(pos + 1);
    return 0;
}