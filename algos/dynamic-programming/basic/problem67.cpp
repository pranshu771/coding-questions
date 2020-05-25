#include<bits/stdc++.h>
using namespace std;

long long int minCost(int *cost,int n,int w) {
    long long int dp[w + 1] = {0};
    memset(dp, 1, sizeof(dp));

    dp[0] = 0;

    for (int i = 1; i <= w;i++) {
        long long int minimum = INT_MAX;
        for (int j = 0; j < min(i,n); j++)
        {
            if(cost[j]!=-1) 
                minimum = min(minimum, dp[i - j - 1] + cost[j]);
        }
        dp[i] = minimum;
    }

    return dp[w];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int k;
        cin >> k;

        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        
        unordered_map<int, int> m;
        long long int ans = minCost(arr, n, k);
        if(ans>=INT_MAX) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}
