#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n,int start,int sum) {
    if(sum==0) {
        return 1;
    }
    if(sum<0) {
        return 0;
    }
    if(start==n) {
        return 0;
    }

    
        return solve(arr,n,start+1,sum-arr[start])+solve(arr,n,start+1,sum);
    
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
        int ans=solve(arr,n,0,sum);
        cout<<ans<<endl;
    }
}