#include<bits/stdc++.h>
using namespace std;

void solve(int w,int *value,int *weight,int n) {

    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= w;j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(weight[i-1]<=j) {
                if(dp[i-1][j]>dp[i-1][j-weight[i-1]]) {
                    dp[i][j] = dp[i - 1][j];
                    
                }
                else {
                    dp[i][j] = dp[i - 1][j - weight[i - 1]]+value[i-1];
                    
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int res = dp[n][w];
    for

    return;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,w;
        cin>>n>>w;

        int *weight = new int[n];
        int *value = new int[n];

        for (int i = 0; i < n;i++) {
            cin >> weight[i];
        }
        for (int i = 0; i < n;i++) {
            cin >> value[i];
        }

        solve(w, value, weight, n);
    }
}