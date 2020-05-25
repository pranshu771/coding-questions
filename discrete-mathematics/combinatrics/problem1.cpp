#include<bits/stdc++.h>
using namespace std;

int solve(int n) {

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;

    for (int i = 3; i <= n;i++) {
        //dp[i][0]=dp[i-1][1];
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin>>n;

        int ans = solve(n);
        cout << ans << endl;
    }
}