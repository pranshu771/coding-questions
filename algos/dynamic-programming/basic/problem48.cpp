#include<bits/stdc++.h>
using namespace std;

int maximumGames(int n) {
    int dp[n]={0};
    dp[0]=1;
    dp[1]=2;

    int i=2;
    do {
        dp[i]=dp[i-1]+dp[i-2];
    }
    while(dp[i++]<=n);

    return i-2;






}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=maximumGames(n);
        cout<<ans<<endl;
    }
}