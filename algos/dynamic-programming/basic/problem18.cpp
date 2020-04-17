#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maximumCost(int *arr,int n,int length) {
    int dp[n]={0};

    dp[0]=0;
    
    for(int i=1;i<=n;i++) {
        int maximum=INT_MIN;
        for(int j=0;j<i;j++) {
            maximum=max(maximum,arr[j]+dp[i-j-1]);
        }
        dp[i]=maximum;
    }
    return dp[n];

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

        map<int,int> m;
        int ans=maximumCost(arr,n,n);
        cout<<ans<<endl;
    }
}