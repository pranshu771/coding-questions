#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define M 1000000007


long long int solve(int n,int k) {
    long long int dp[n+1]={0};
    dp[0]=0;
    dp[1]=k;
    dp[2]=(k*k);
    for(int i=3;i<=n;i++) {
        dp[i]=((dp[i-1]+dp[i-2])*(k-1))%M;
    }
    return dp[n]%M;



}
int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        int k;
        cin>>n>>k;

        long long int ans=solve(n,k);
        cout<<ans<<endl;
    }
}