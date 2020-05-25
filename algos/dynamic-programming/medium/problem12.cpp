#include<bits/stdc++.h>
using namespace std;



int unboundedKnapsnack(int w,int *val,int *weight,int n) {
    int dp[w + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j < n;j++) {
            if(weight[j] <= i) {
                dp[i] = max(dp[i], val[j] + dp[i - weight[j]]);
            }
            
        }
    }
    return dp[w];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n, w;
        cin >> n >> w;

        int *val = new int[n];
        int *weight = new int[n];
        for (int i = 0; i < n;i++) {
            cin >> val[i];
        }
        for (int i = 0; i < n;i++) {
            cin >> weight[i];
        }

        int ans = unboundedKnapsnack(w, val, weight, n);
        cout << ans << endl;

    }
}