#include<bits/stdc++.h>
using namespace std;

bool isValid(int i,int j,int r,int c) {
    if(i<r&&i>=0&&j<c&&j>=0) {
        return true;
    }
    else {
        return false;
    }
}

double maximumAverageValue(int **arr,int n) {
    int dp[n][n]={0};
    memset(dp,0,sizeof(dp));
    dp[0][0]=arr[0][0];
    int up,left;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==0&&j==0) {

            }
            else {
                up=0;
                left=0;
                if(isValid(i-1,j,n,n)) {
                    up=dp[i-1][j];
                }
                if(isValid(i,j-1,n,n)) {
                    left=dp[i][j-1];
                }
                dp[i][j]=(arr[i][j]+max(up,left));
                
            }
        }
    }
    
    return (double)dp[n-1][n-1]/(2*n - 1);
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        int **arr=new int*[n];
        for(int i=0;i<n;i++) {
            arr[i]=new int[n];
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>arr[i][j];
            }
        }

        double ans=maximumAverageValue(arr,n);
        cout<<ans<<endl;


    }
}