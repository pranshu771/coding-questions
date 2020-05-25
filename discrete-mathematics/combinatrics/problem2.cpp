#include<bits/stdc++.h>
using namespace std;

int C(int n,int r) {
    int dp[r + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i = 1; i <= r;i++) {
        dp[i] = dp[i - 1] * (n - i + 1) / i;
    }
    return dp[r];
}

int solve(int n) {
    int ans = 0;
    for (int i = 2; i <= n; i+=2)
    {
        ans += (C(n, i) * pow(9, n - i));
    }
    return ans;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=solve(n);
        cout<<ans<<endl;

    }
}