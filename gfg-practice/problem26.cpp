#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// int solve(string s, int start, int end)
// {
//     if (start > end)
//     {
//         return 0;
//     }

//     if (end - start == 0)
//     {
//         return 1;
//     }

//     if (s[start] == s[end])
//     {
//         return solve(s, start, end - 1) + solve(s, start + 1, end) + 1;
//     }
//     else
//     {
//         return solve(s, start, end - 1) + solve(s, start + 1, end) - solve(s, start + 1, end - 1);
//     }
// }

int solve(string s)
{
    int length = s.length();
    if (length == 0)
    {
        return 0;
    }
    if (length == 1)
    {
        return 1;
    }

    int dp[length][length];
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < length; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            }
        }
    }
    return dp[0][length - 1];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string S;
        cin >> S;

        int ans = solve(S);
        cout << ans << endl;
    }
}