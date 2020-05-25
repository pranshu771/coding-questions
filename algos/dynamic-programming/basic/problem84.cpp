#include<bits/stdc++.h>
using namespace std;

int solve(int h) {
    int dp[h + 1] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= h;i++) {
        dp[i] = dp[i - 1] * (dp[i - 1] + 2 * dp[i - 2]);
    }
    return dp[h];
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