//Given an unsorted array having both negative and positive integers. The task is place all negative element at the end of array without changing the order of positive element and negative element.

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(int *arr,int n) {
    int *temp=new int[n];
    int j=0;
    for(int i=0;i<n;i++) {
        if(arr[i]>=0) {
            temp[j++]=arr[i];
        }
    }
    for(int i=0;i<n;i++) {
        if(arr[i]<0) {
            temp[j++]=arr[i];
        }
    }
    for(int i=0;i<n;i++) {
        arr[i]=temp[i];
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