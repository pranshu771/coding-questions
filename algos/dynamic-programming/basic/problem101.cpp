#include<bits/stdc++.h>
using namespace std;

int C(int n,int r) {
    int dp[r + 1];
    dp[0] = 1;
    for (int i = 1; i <= r;i++) {
        dp[i] = dp[i - 1] * (n - i + 1) / i;
    }
    return dp[r];
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cout << C(9 + n, n) << endl;
    }
}