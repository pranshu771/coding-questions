//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool solve(int *arr,int n,int start,int sum) {
    if(sum==0) {
        return true;
    }
    if(sum<0) {
        return false;
    }
    if(start==n) {
        return false;
    }

    for(int i=start;i<n;i++) {
        return solve(arr,n,i+1,sum-arr[i])||solve(arr,n,i+1,sum);
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
        int sum;
        cin>>sum;
        if(solve(arr,n,0,sum)) {
            cout<<"YES"<<endl;
        }        
        else {
            cout<<"NO"<<endl;
        }
    }
}