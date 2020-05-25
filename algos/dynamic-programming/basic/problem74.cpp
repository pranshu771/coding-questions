#include<bits/stdc++.h>
using namespace std;

int toNum(string s) {
    int num = 0;
    int length = s.length();

    for (int i = 0; i < length;i++) {
        num = num * 10 + (s[i] - 48);
    }
    return num;
}

// int solve(string s) {
//     int length = s.length();
//     if(length==1) {
//         return s[0] - 48;
//     }

//     char a = s[length - 1];
//     s = s.substr(0, length - 1);
//     length--;

//     int num = solve(s);
//     for (int i = 0; i < length;i++) {
//         num = num + (toNum(s.substr(i, length - i))) * 10 + (a - 48);
//     }
//     num += (a - 48);
//     return num;
// }

int solve(string s) {
    int l = s.length();
    int dp[l];
    memset(dp, 0, sizeof(dp));

    int *num = new int[l];
    for (int i = 0; i < l;i++) {
        num[i] = (s[i] - 48);
    }

    

    dp[0] = num[0];
    int res = dp[0];
    for (int i = 1; i < l; i++)
    {
        dp[i] = (i + 1) * num[i] + dp[i - 1] * 10;
        res += dp[i];
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int ans = solve(s);
        cout << ans << endl;
    }
}