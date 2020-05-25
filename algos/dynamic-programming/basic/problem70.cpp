    #include<bits/stdc++.h>
    using namespace std;

    int solve(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;

        for (int i = 4; i <= n;i++) {
            int res = dp[i - 1];
            if(i%2==0) {
                res = min(res, dp[i / 2]);
            }
            if(i%3==0) {
                res = min(res, dp[i / 3]);
            }
            dp[i] = res + 1;
        }
        return dp[n];
    }

    int main() {
        int t;
        cin>>t;

        while(t--) {
            int n;
            cin>>n;

            int ans = solve(n);
            cout << ans << endl;
        }
    }