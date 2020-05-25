#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int solve(string s)
{
    int length = s.length();
    if (length <= 1)
    {
        return 0;
    }

    int start = 0;
    int end = 0;
    int sum = 0;
    int count = -1;

    for (int i = 0; i < length; i++)
    {
        start = i;
        end = i;
        count = -1;

        while (start >= 0 && end < length && (s[start] == s[end]))
        {
            start--;
            end++;
            count++;
        }

        sum += count;

        start = i;
        end = i + 1;
        count = 0;
        while (start >= 0 && end < length && (s[start] == s[end]))
        {
            start--;
            end++;
            count++;
        }

        sum += count;
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
        string s;
        cin >> s;

        int ans = solve(s);
        cout << ans << endl;
    }
}