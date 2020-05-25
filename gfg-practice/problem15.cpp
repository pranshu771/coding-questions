#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int solve(int n)
{
    return (n) * (n + 1) * (pow(2, n - 1)) / 2;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ans = solve(n);
        cout << ans << endl;
    }
}