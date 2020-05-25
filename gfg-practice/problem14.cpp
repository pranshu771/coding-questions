#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int solve(int *arr, int n)
{
    int cnt = 0;
    int sum = 0;
    int product = 0;
    for (int i = 0; i < n; i++)
    {
        sum = arr[i];
        product = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            if (sum > product)
            {
            }
            else if (sum == product)
            {

                cnt++;
            }
            else
            {
                break;
            }
            sum += arr[j];
            product *= arr[j];
        }
        if(sum==product) {
            cnt++;
        }
    }
    return cnt;
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