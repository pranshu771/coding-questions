#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool solve(int *arr,int n,int m) {
    bool dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=n;i++) {
        dp[i][0]=true;
    }
    for(int j=1;j<=m;j++) {
        dp[0][j]=false;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(j<arr[i-1]) {
                dp[i][j]=dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][m];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,m;
        cin>>n>>m;
        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        for(int i=0;i<n;i++) {
            arr[i]=arr[i]%m;
        }
        if(n>m) {
            cout<<1;
        }
        else {
            if(solve(arr,n,m)) {
                cout<<1;
            }
            else {
                cout<<0;
            }
        }
        cout<<endl;
    }
}