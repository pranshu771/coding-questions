#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct cells
{
    int rs, cs;

    //  indices of end cell
    int re, ce;
    cells(int rs, int cs, int re, int ce) : rs(rs), cs(cs), re(re), ce(ce) {}

    bool operator<(const cells &other) const
    {
        return ((rs != other.rs) || (cs != other.cs) ||
                (re != other.re) || (ce != other.ce));
    }
};

map<cells, int> memo;

int solve(char **mat, int rs, int re, int cs, int ce, int m, int n)
{
    if (rs < 0 || rs >= m || cs < 0 || cs >= n)
        return 0;
    if (re < 0 || re < rs || ce < 0 || ce < cs)
        return 0;

    if (mat[rs][cs] != mat[re][ce])
    {
        return 0;
    }

    if (abs((re - rs) + (ce - cs)) <= 1)
    {
        return 1;
    }

    if (memo.find(cells(rs, re, cs, ce)) != memo.end())
    {
        return memo[cells(rs, re, cs, ce)];
    }

    int ret = solve(mat, rs + 1, re - 1, cs, ce, m, n) + solve(mat, rs, re - 1, cs + 1, ce, m, n) +
              solve(mat, rs + 1, re, cs, ce - 1, m, n) + solve(mat, rs, re, cs + 1, ce - 1, m, n);

    memo[cells(rs, re, cs, ce)] = ret;
    return ret;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n;
        char **mat = new char *[m];
        for (int i = 0; i < m; i++)
        {
            mat[i] = new char[n];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        int ans = solve(mat, 0, m - 1, 0, n - 1, m, n);
        cout << ans << endl;
    }
}