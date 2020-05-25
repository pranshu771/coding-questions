#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int solve(int *arr, int n)
{
    int IS[n];
    int DS[n];

    for (int i = 0; i < n; i++)
    {
        IS[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                IS[i] = max(IS[i], IS[j] + arr[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        DS[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                DS[i] = max(DS[i], DS[j] + arr[i]);
            }
        }
    }

    int sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = max(IS[i] + DS[i] - arr[i], sum);
    }
    return sum;
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