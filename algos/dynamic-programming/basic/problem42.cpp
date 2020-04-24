#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n) {
    int dp[n]={1};
    memset(dp,1,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<n;i++) {
        dp[i]=1;
        for(int j=0;j<i;j++) {
            if(abs(arr[i]-arr[j])==1) {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    int maximum=INT_MIN;
    for(int i=0;i<n;i++) {
        maximum=max(maximum,dp[i]);
    }

    return maximum;
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

        int ans=solve(arr,n);
        cout<<ans<<endl;
    }
}