#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int dp[n + 1] = {0};
    for (int i = 0; i <= n;i++) {
        dp[i] = 0;
    }

    dp[0] = 1;
    for (int i = 3; i <= n;i++) {
        dp[i] += dp[i - 3];
    }
    for (int i = 5; i <= n;i++) {
        dp[i] += dp[i - 5];
    }
    for (int i = 10; i <= n;i++) {
        dp[i] += dp[i - 10];
    }
    return dp[n];
}

//if all combinations are treated different.

// int solve(int n) {
//     int dp[n + 1];

//     for (int i = 0; i < n;i++) {
//         dp[i] = 0;
//     }
//         dp[0] = 1;

//     for (int i = 3; i <= n;i++) {
//         if(i<5) {
//             dp[i] = dp[i - 3];
//         }
//         else if (i < 10) {
//             dp[i] = dp[i - 3] + dp[i - 5];
//         }
//         else {
//             dp[i] = dp[i - 3] + dp[i - 5] + dp[i - 10];
//         }
//     }
//     return dp[n];
// }

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