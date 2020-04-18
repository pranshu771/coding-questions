#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int newmanConway(int n) {
    int dp[n+1]={0};
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++) {
        dp[i]=dp[dp[i-1]]+dp[i-dp[i-1]];
    }
    return dp[n];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=newmanConway(n);
        cout<<ans<<endl;
    }
}