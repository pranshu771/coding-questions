#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int solve(string s)
{
    if (s.length() == 1)
    {
        return 1;
    }
    int length = s.length();

    if (length % 2 == 0)
    {

        string first = s.substr(0, length / 2);
        string second = s.substr(length / 2, length / 2);

        if (first == second)
        {
            return 1 + solve(first);
        }
        else
        {
            return 1 + solve(s.substr(0, length - 1));
        }
    }
    else
    {
        return 1 + solve(s.substr(0, length - 1));
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string S;
        cin >> S;

        cout << solve(S) << endl;
    }
}