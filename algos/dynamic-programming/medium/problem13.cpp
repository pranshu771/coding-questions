#include<bits/stdc++.h>
using namespace std;

struct temple {
    int left;
    int right;
};


int solve(int *arr, int n)
{
    temple dp[n];
    dp[0].left = 0;
    dp[n - 1].right = 0;

    for (int i = 1; i < n;i++) {
        if(arr[i]>arr[i-1]) {
            dp[i].left = dp[i - 1].left + 1;
        }
        else {
            dp[i].left = 0;
        }
    }

    for (int i = n - 2; i >= 0;i--) {
        if(arr[i]>arr[i+1]) {
            dp[i].right = dp[i + 1].right + 1;
        }
        else {
            dp[i].right = 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < n;i++) {
        sum += (max(dp[i].left, dp[i].right) + 1);
    }

    return sum;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int *heights=new int[n];
        for(int i=0;i<n;i++) {
            cin>>heights[i];
        }
        int ans = solve(heights, n);
        cout << ans << endl;
    }
}