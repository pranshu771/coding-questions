#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maximumBitonic(int *arr,int n) {
    pair<int,bool> dp[n];

    dp[0].first=arr[0];
    dp[0].second=false;

    for(int i=1;i<n;i++) {
        dp[i].first=arr[i];

        for(int j=0;j<i;j++) {
            if(dp[j].second==false) {
                if(dp[j].first+arr[i]>dp[i].first) {
                    dp[i].first=dp[j].first+arr[i];
                    if(arr[i]<arr[j]) {
                        dp[i].second=true;
                    }
                    else {
                        dp[i].second=false;
                    }
                }
            }
            else {
                if(arr[i]<arr[j]) {
                    if(dp[j].first+arr[i]>dp[i].first) {
                        dp[i].first=dp[j].first+arr[i];
                    }
                }
            }
        }
    }

    int maximum=INT_MIN;
    for(int i=0;i<n;i++) {
        maximum=max(maximum,dp[i].first);
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

        int ans=maximumBitonic(arr,n);
        cout<<ans<<endl;
    }
}