using namespace std; 
#include<bits/stdc++.h>
#define M 1000000007

int subsequenceCount(string S,string T) {
    int sl=S.length();
    int tl = T.length();

    int dp[sl+1][tl+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= sl;i++) {

        dp[i][0] = 1;
    }

    for (int i = 1; i <= tl;i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= sl;i++) {
        for (int j = 1; j <= tl;j++) {
            if(S[i-1]==T[j-1]) {
                dp[i][j] = dp[i - 1][j]%M + dp[i - 1][j - 1]%M;
            }
            else {
                dp[i][j] = dp[i - 1][j]%M;
            }
        }
    }
    return dp[sl][tl]%M;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string S, T;
        cin >> S >> T;

        int ans = subsequenceCount(S, T);
        cout << ans << endl;
    }
}