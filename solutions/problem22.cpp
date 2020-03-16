#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(int *arr,int n) {
    int start=0;
    int end=n-1;
    
    int count=min(zeroes,ones);
    while(start<end) {
        while(arr[start]==0&&(start<end)) {
            start++;
        }
        while(arr[end]==1&&(start<end)) {
            end--;
        }
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    }
}