#include<bits/stdc++.h>
using namespace std;

long long int solve(long long int n) {
    int dp[n+1]={0};
    dp[0]=0;
    for(int i=1;i<=n;i++) {
        dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
    }
    return dp[n];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        long long int n;
        cin>>n;

        long long int ans=solve(n);
        cout<<ans<<endl;
    }
}