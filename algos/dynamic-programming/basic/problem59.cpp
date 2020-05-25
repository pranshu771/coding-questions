#include<bits/stdc++.h>
using namespace std;

int maximumSumNOAdjacent(int **arr,int n) {

    int dp[n]={0};
    memset(dp,0,sizeof(dp));
    dp[0]=max(arr[0][0],arr[1][0]);
    dp[1]=max(arr[0][0],max(arr[0][1],max(arr[1][0],arr[1][1])));

    for(int i=2;i<n;i++) {
        dp[i]=max(dp[i-1],dp[i-2]+max(arr[0][i],arr[1][i]));
    }
    return dp[n-1];
}

int main() {
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;

        int **arr=new int*[2];
        for(int i=0;i<2;i++) {
            arr[i]=new int[n];
        }

        for(int i=0;i<2;i++) {
            for(int j=0;j<n;j++) {
                cin>>arr[i][j];
            }
        }
        int ans=maximumSumNOAdjacent(arr,n);
        cout<<ans<<endl;
        }
    
}