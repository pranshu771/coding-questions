#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool isPal(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
    }
    return true;
}

bool solve(string s, int k)
{
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;

        bool ans = solve(s, k);
        cout << ans << endl;
    }
}