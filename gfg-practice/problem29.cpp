#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define M 1000000007

int solve(int *a, int *b, int m, int n, int k)
{
    if (k > m + n)
    {
        return -1;
    }
    int it1 = 0;
    int it2 = 0;
    int num;

    while (it1 < m && it2 < n)
    {
        if (a[it1] < b[it2])
        {
            num = a[it1];
            it1++;
        }
        else
        {
            num = b[it2];
            it2++;
        }
        if (k == 1)
        {
            return num;
        }
        k--;
    }

    if (it1 != m)
    {
        return a[it1 + k - 1];
    }
    else
    {
        return b[it2 + k - 1];
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n, k;
        cin >> m >> n >> k;

        int *a = new int[m];
        int *b = new int[n];

        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int ans = solve(a, b, m, n, k);
        cout << ans << endl;
    }
}