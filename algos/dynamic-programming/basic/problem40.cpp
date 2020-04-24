#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//solved with DP
int countProductLessThanKDP(int *arr,int n,int k) {
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++) {
        
        for(int j=1;j<=k;j++) {
            dp[i][j]=dp[i-1][j];
            if(arr[i-1]<=j&&arr[i-1]>0) {
                dp[i][j]+=dp[i-1][j/arr[i-1]]+1;
            }

        }
    }
    return dp[n][k];




}

//solves by recursion
int countProductLessThanK(int *arr,int n,int k) {

    if(k<=0) {
        return 0;
    }
    if(n==1) {
        if(arr[0]<=k) {
            return 1;
        }
        return 0;
    }

    int ans=countProductLessThanK(arr,n-1,k);

    if(arr[n-1]<=k&&arr[n-1]>0) {
        ans+=countProductLessThanK(arr,n-1,k/arr[n-1])+1;
    }
    return ans;
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

        int k;
        cin>>k;

        //int ans=countProductLessThanK(arr,n,k);
        int ans=countProductLessThanKDP(arr,n,k);
        cout<<ans<<endl;
        int a=-9;
        cout<<a%4;
    }
}