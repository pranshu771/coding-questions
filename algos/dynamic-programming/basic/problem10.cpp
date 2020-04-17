#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(int *arr,int n,int sum) {
    
    bool dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=n;i++) {
        dp[i][0]=true;
    }

    for(int i=1;i<=sum;i++) {
        dp[0][i]=false;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum;j++) {
            if(j<arr[i-1]) {
                dp[i][j]=dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];

}

int summation(int *arr,int n) {
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
    return sum;
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

        int sum=summation(arr,n);
        if(sum%2) {
            cout<<"NO"<<endl;
            return 0;
        }
        if(solve(arr,n,sum/2)) {
            cout<<"YES";
        }
        else {
            cout<<"NO";
        }
        cout<<endl;
    }
}