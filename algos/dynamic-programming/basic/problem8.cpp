#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int solve(int *arr,int n,int sum) {
    int dp[n][sum+1];

    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++) {
        dp[i][0]=1;
    }

    for(int j=1;j<=sum;j++) {
        for(int i=0;i<n;i++) {
            int x,y;
            if(j-arr[i]>=0) {
                x=dp[i][j-arr[i]];
            }
            else {
                x=0;
            }
            if(i-1>=0) {
                y=dp[i-1][j];
            }
            else {
                y=0;
            }
            dp[i][j]=x+y;
        }
    }

    return dp[n-1][sum];

}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int sum;
        cin>>sum;
        int ans=solve(arr,n,sum);
        cout<<ans<<endl;
    }
}