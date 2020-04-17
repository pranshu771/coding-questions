#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n) {
    
    sort(arr,arr+n);
    int dp[n]={0};
    dp[n-1]=1;

    for(int i=n-2;i>=0;i--) {
        int mxm=0;
        for(j=i+1;j<n;j++) {
            if(arr[j]%arr[i]==0) {
                mxm=max(mxm,dp[j]);
            }
        }
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

        int ans=solve(arr,n);
    }
}