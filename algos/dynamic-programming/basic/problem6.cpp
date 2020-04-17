#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int n,int r) {
    int dp[r+1]={0};
    dp[0]=1;
    for(int i=1;i<=r;i++) {
        dp[i]=dp[i-1]*(n-i+1);
    }
    return dp[r];
    
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,r;
        cin>>n>>r;

        int ans=solve(n,r);
        cout<<ans<<endl;
    }
}