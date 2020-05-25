#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int dp[n + 1] = {0};

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n;i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i < 2)
        {
            dp[i] = dp[i - 1];
        }
        else if (i < 3)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }
    return dp[n];
}

int solve(int n) {
    int cur, prev1, prev2, prev3;

}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=solve(n);
        cout << ans << endl;
    }
}