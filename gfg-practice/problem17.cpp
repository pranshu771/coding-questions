#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int solve(int *arr, int n)
{
    int a = 0;
    int b = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = b;
        b = min(a + arr[i], b + arr[i]);
        a = temp;
    }
    return min(a, b);
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