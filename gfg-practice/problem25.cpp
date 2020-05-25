#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int summation(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// bool solve(int *arr, int n, int sum)
// {

//     bool dp[n + 1][sum + 1];
//     memset(dp, 0, sizeof(dp));
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 1;
//     }
//     for (int i = 1; i <= sum; i++)
//     {
//         dp[0][i] = 0;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= sum; j++)
//         {
//             if (j < arr[i - 1])
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
//             }
//         }
//     }

//     return dp[n][sum];
// }

bool solve(int *arr, int n, int sum)
{
    if (n == 0 && sum != 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }

    if(arr[n-1]>sum) {
        return solve(arr, n - 1, sum);
    }

    return solve(arr, n - 1, sum) || solve(arr, n - 1, sum - arr[n - 1]);
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

        int k;
        cin >> k;
        int sum = summation(arr, n);
        if (sum % k)
        {
            cout << 0;
        }
        else
        {
            bool ans = solve(arr, n, sum / k);
            cout << ans;
        }
        cout << endl;
    }
}