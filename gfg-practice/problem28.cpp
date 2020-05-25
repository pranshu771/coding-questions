#include <iostream>
using namespace std;
#include <bits/stdc++.h>

map<string, int> m;

int solve(string s, int n)
{

    int start = 0;
    int ending = 0;
    int sum = 0;
    int count = -1;
    int length = s.length();

    for (int i = 0; i < length; i++)
    {
        start = i;
        ending = i;
        count = 0;

        while (start >= 0 && ending < length && (s[start] == s[ending]))
        {

            if (m.find(s.substr(start, ending - start + 1)) == m.end())
            {
                m[s.substr(start, ending - start + 1)] = 1;
                count++;
            }
            start--;
            ending++;
        }

        sum += count;

        start = i;
        ending = i + 1;
        count = 0;
        while (start >= 0 && ending < length && (s[start] == s[ending]))
        {

            if (m.find(s.substr(start, ending - start + 1)) == m.end())
            {
                m[s.substr(start, ending - start + 1)] = 1;
                count++;
            }
            start--;
            ending++;
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

        string s;
        cin >> s;

        int ans = solve(s, s.length());
        cout << ans << endl;
    }
}