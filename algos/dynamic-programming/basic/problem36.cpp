#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,string s3,int l1,int l2,int l3) {
    int dp[l1+1][l2+1][l3+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<l1;i++) {
        dp[i][0][0]=0;
    }

    for(int i=0;i<l2;i++) {
        dp[0][i][0]=0;
    }

    for(int i=0;i<l3;i++) {
        dp[0][0][i]=0;
    }


    for(int i=1;i<=l1;i++) {
        for(int j=1;j<=l2;j++) {
            for(int k=1;k<=l3;k++) {
                if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1]) {
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }
                else {
                    int arr[6]={0};
                    arr[0]=dp[i-1][j][k];
                    arr[1]=dp[i][j-1][k];
                    arr[2]=dp[i][j][k-1];
                    arr[3]=dp[i-1][j-1][k];
                    arr[4]=dp[i-1][j][k-1];
                    arr[5]=dp[i][j-1][k-1];

                    int maximum=INT_MIN;
                    for(int i=0;i<6;i++) {
                        maximum=max(maximum,arr[i]);
                    }
                    dp[i][j][k]=maximum;
                }
            }
        }
    }

    return dp[l1][l2][l3];

}

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s1,s2,s3;
        int l,m,n;
        cin>>l>>m>>n;
        cin>>s1>>s2>>s3;

        int ans=LCS(s1,s2,s3,l,m,n);
        cout<<ans<<endl;
    }
}