#include<bits/stdc++.h>
using namespace std;



int solve(int n,int k) {
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n;i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int i = 0; i <= k;i++) {
        dp[0][i] = 0;
        dp[1][i] = i;
    }

    int minimum = INT_MAX;
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][x - 1], dp[i][j - x]) + 1);
            }
        }
    }
    return dp[n][k];
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin>>n>>k;
        int ans = solve(n, k);
        cout << ans << endl;
    }
}