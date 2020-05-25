#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int dp[2][n + 1];
    dp[0][1] = 1;
    dp[1][1] = 2;

    for (int i = 2; i <= n;i++) {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];

        dp[1][i] = dp[0][i - 1] * 2 + dp[1][i - 1];
    }
    return dp[0][n] + dp[1][n];
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int ans = solve(n);
        cout << ans << endl;



    }
}