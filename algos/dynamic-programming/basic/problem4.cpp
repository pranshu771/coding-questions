#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int bell(int n) {
    int dp[n+1][n+1]={0};
    dp[0][0]=0;
    dp[1][0]=0;
    dp[1][1]=1;

    for(int i=2;i<=n;i++) {
        for(int j=0;j<=i;j++) {
            dp[i][j]=dp[i-1][j-1]+j*dp[i-1][j];
        }
    }

    int sum=0;
    for(int i=0;i<=n;i++) {
        sum+=dp[n][i];
    }
    return sum;
} 

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=bell(n);
        cout<<ans<<endl;
    }
}