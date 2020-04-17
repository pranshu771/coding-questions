#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n) {
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }
    return dp[n];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            arr[i]=i+1;
        }
        int ans=solve(arr,n);
        cout<<ans<<endl;
    }
}