#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(int i,int j,int n,int m) {
    if(i>=0&&i<n&&j>=0&&j<m) {
        return true;
    }
    return false;
}



int maximumGold(int **arr,int n,int m) {
    int dp[n][m]={0};
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++) {
        dp[i][0]=arr[i][0];
    }

    for(int j=1;j<m;j++) {
        for(int i=0;i<n;i++) {
            int max=INT_MIN;
            if(isValid(i,j-1,n,m)) {
                if(arr[i][j]+dp[i][j-1]>max) {
                    max=arr[i][j]+dp[i][j-1];
                }
            }
            if(isValid(i+1,j-1,n,m)) {
                if(arr[i][j]+dp[i+1][j-1]>max) {
                    max=arr[i][j]+dp[i+1][j-1];
                }
            }
            if(isValid(i-1,j-1,n,m)) {
                if(arr[i][j]+dp[i-1][j-1]>max) {
                    max=arr[i][j]+dp[i-1][j-1];
                }
            }
            dp[i][j]=max;
        }
    }

    int max=INT_MIN;
    for(int i=0;i<n;i++) {
        if(dp[i][m-1]>max) {
            max=dp[i][m-1];
        }
    }
    return max;




}


int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,m;
        cin>>n>>m;
        int **arr=new int*[n];
        for(int i=0;i<n;i++) {
            arr[i]=new int[m];
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
            }
        }

        

        int ans=maximumGold(arr,n,m);
        cout<<ans<<endl;

    }
}