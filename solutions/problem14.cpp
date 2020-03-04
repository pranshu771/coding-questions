#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int findPivot(int *arr,int l,int h) {
    if(l>=h) {
        return -1;
    }
    int mid=(l+h)/2;
    if(arr[mid]<arr[mid+1]) {
        
        if(findPivot(arr,l,mid)==-1&&findPivot(arr,mid+1,h)==-1) {
            return -1;
        }
        else if(findPivot(arr,l,mid)!=-1) {
            return findPivot(arr,l,mid);
        }
        else if(findPivot(arr,mid+1,h)!=-1) {
            return findPivot(arr,mid+1,h);
        }
    }
    else {
        return mid;
    }
}

bool solve(int *arr,int n,int k) {
    int pivotIndex=findPivot(arr,0,n-1);
    int start=pivotIndex+1;
    int end=pivotIndex;
    while(start<n) {
        
        if(arr[start]+arr[end]==k) {
            return true;
        }
        else if(arr[start]+arr[end]<k) {
            start++;
        }
        else {
            end--;
        }
    }
    start=0;
    while(start<end) {
        if(arr[start]+arr[end]==k) {
            return true;
        }
        else if(arr[start]+arr[end]<k) {
            start++;
        }
        else {
            end--;
        }
    }
    return false;
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
        int k;
        cin>>k;
        bool ans=solve(arr,n,k);
        cout<<ans<<endl;
    }
}