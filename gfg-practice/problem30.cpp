#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool checkPal(int n)
{
    int divisor = 1;
    int num = n;
    while (num != 0)
    {
        divisor *= 10;
        num = num / 10;
    }
    divisor /= 10;

    int leading = (n / divisor) % 10;
    int trailing = n % 10;

    while (n != 0)
    {
        leading = n / divisor;
        trailing = n % 10;

        if (leading != trailing)
        {
            return false;
        }

        n = (n % divisor) / 10;
        divisor = divisor / 100;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool ans = checkPal(n);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}