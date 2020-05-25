#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n) {
    int dp[n];
    for (int i = 0; i < n;i++) {
        dp[i] = 1;
    }
    int len = -1;

    for (int i = 1; i < n;i++) {
        for (int j = 0; j < i;j++) {
            if(arr[i]>arr[j]&&(i-j)<=arr[i]-arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        len = max(len, dp[i]);
    }
    return n - len;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n;i++) {
            cin >> arr[i];
        }

        int ans = solve(arr, n);
        cout << ans << endl;
    }
}