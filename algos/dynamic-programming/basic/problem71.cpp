#include<bits/stdc++.h>
using namespace std;

int minEdits(string s1,string s2,int l1,int l2) {
    int dp[l1 + 1][l2 + 1];
    memset(dp, 0, sizeof(dp));
    

    for (int i = 0; i <= l1;i++) {
        for (int j = 0; j <= l2;j++) {
            if(i==0) {
                dp[i][j] = j;
            }
            else if(j==0) {
                dp[i][j] = i;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[l1][l2];
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int l1, l2;
        cin >> l1 >> l2;
        string s1, s2;
        cin >> s1 >> s2;
        int ans = minEdits(s1, s2, s1.length(), s2.length());
        cout << ans << endl;
    }
}