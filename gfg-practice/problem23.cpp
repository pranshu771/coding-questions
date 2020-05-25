#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int expand(string s, int start, int end)
{
    int length = s.length();
    if (length == 0 || (start > end))
    {
        return 0;
    }

    while (start >= 0 && end < length && (s[start] == s[end]))
    {
        start--;
        end++;
    }
    return end - start - 1;
}

void solve(string s)
{
    int length = s.length();

    int start = 0;
    int end = 0;
    for (int i = 0; i < length; i++)
    {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i + 1);
        int len = max(len1, len2);
        if (len > end - start + 1)
        {
            start = i - ((len - 1) / 2);
            end = i + (len / 2);
        }
    }
    cout << s.substr(start, end - start + 1) << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        solve(s);
    }
}