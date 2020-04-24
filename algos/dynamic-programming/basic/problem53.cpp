#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n,int k) {
    int dp[n]={0};
    dp[0]=0;

    for(int i=1;i<n;i++) {
        dp[i]=dp[i-1];
        if(arr[i]-arr[i-1]<k) {
            if(i<2) {
                dp[i]=arr[i]+arr[i-1];
            }
            else {
                dp[i]=dp[i-2]+arr[i]+arr[i-1];
            }
        }
    }
    return dp[n-1];
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
        sort(arr,arr+n);
        int k;
        cin>>k;

        int ans=solve(arr,n,k);
        cout<<ans<<endl;

    }
}