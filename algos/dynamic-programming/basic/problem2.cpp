
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define M 1000000007

int fibo(int n) {
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++) {
        dp[i]=(dp[i-1]%M+dp[i-2]%M)%M;
    }
    return dp[n]%M;

}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=fibo(n);
        cout<<ans<<endl;
    }
}