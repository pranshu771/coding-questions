#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int solve(int *arr, int n)
{
    int dp[n][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 10000;
    dp[0][1] = arr[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][1] = max(dp[i - 1][1] + arr[i], arr[i]);
        dp[i][0] = max(dp[i - 1][0] + arr[i], dp[i - 1][1]);
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(dp[i][0], max(dp[i][1], ans));
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = solve(arr, n);
        cout << ans << endl;
    }
}