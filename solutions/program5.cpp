//Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative o
#include<iostream>
using namespace std;

void solve(int *arr,int n) {
    for(int i=1;i<n;i++) {
        if(i%2) {
            if(arr[i-1]>arr[i]) {
                int temp=arr[i-1];
                arr[i-1]=arr[i];
                arr[i]=temp;
            }
        }
        else {
            if(arr[i-1]<arr[i]) {
                int temp=arr[i-1];
                arr[i-1]=arr[i];
                arr[i]=temp;
            }
        }
        
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        solve(arr,n);
        cout<<endl;
    }
    
}