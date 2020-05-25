#include<bits/stdc++.h>
using namespace std;

// int solve(int m,int n,int x) {

//     if(x<=0) {
//         return 0;
//     }
//     if(n==1) {
//         if(x>m) {
//             return 0;
//         }
    
//         else {
//             return 1;
//         }
//     }
    

//     int ways=0;
//     for (int i = 1; i <= m;i++) {
//         ways += solve(m, n - 1, x - i);
//     }
//     return ways;
// }

long long int solve(int m,int n,int x) {
    long long int dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < x;j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m && i <= x;i++)
    {
        dp[1][i] = 1;
    }

        for (int i = 2; i <= n; i++)
        {

            for (int j = 1; j <= x; j++)
            {
                dp[i][j] = 0;
                for (int value = 1; value <= m; value++)
                {
                    if (j > value)
                    {
                        dp[i][j] += dp[i - 1][j - value];
                    }
                }
            }
        }
    return dp[n][x];
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int m, n, x;
        cin >> m >> n >> x;
        long long int ans = solve(m, n, x);
        cout << ans << endl;
    }
}