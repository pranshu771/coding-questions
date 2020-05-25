#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int count(int n)
{
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 3];
    }
    for (int i = 5; i <= n; i++)
    {
        dp[i] += dp[i - 5];
    }
    for (int i = 10; i <= n; i++)
    {
        dp[i] += dp[i - 10];
    }

    return dp[n];
}

int

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ways = count(n);
        cout << ways << endl;
    }
}