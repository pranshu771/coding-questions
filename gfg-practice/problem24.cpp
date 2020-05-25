#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int longestPallindromeSubsequence(string s)
{
    int length = s.length();
    int dp[length][length];

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
                if (j - i == 1)
                {
                    dp[i][j] = 2;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
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
        string s;
        cin >> s;

        int ans = longestPallindromeSubsequence(s);
        cout << ans << endl;
    }
}