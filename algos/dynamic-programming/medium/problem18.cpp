#include<bits/stdc++.h>
using namespace std;

int C(int n,int r) {
    int dp[r + 1];
    dp[0] = 1;
    for (int i = 1; i <= r;i++) {
        dp[i] = (dp[i - 1]) * (n - i + 1) / i;
    }
    return dp[r];
}

int solve(int n,int m,int k) {

    if(n>=m*k) {
        return n == m * k;
    }
    if(n<=0) {
        return 0;
    }
    
    if(n==1) {
        return m;
    }
    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += solve(n - i, m - 1, k);
    }
    return sum;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,m,k;
        cin >> n >> m >> k;

        int ans = solve(n, m, k);
        cout << ans << endl;
    }
}