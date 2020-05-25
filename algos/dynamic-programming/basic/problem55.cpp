#include<bits/stdc++.h>
using namespace std;

int maximumSegments(int n,int a,int b,int c) {
    int dp[n+1]={-1};
    memset(dp,-1,sizeof(dp));
    dp[0]=0;

    for(int i=0;i<=n;i++) {

        if(dp[i]==-1)
        continue;

        if(i+a<=n) {
            dp[i+a]=max(dp[i+a],dp[i]+1);
        }
        if(i+b<=n) {
            dp[i+b]=max(dp[i+b],dp[i]+1);
        }
        if(i+c<=n) {
            dp[i+c]=max(dp[i+c],dp[i+1]);
        }
    }    
    return dp[n];
} 

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int ans=maximumSegments(n,a,b,c);
        cout<<ans<<endl;
    }
}