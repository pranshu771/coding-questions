#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LIS(int *arr,int n) {

    int dp[n]={0};
    dp[0]=arr[0];

    for(int i=1;i<n;i++) {
        dp[i]=arr[i];
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j]&&dp[j]+arr[i]>dp[i]) {
                dp[i]=dp[j]+arr[i];
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

        int ans=LIS(arr,n);
        cout<<ans<<endl;
    }
}