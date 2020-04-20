#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool find(char a,string s) {
    for(int i=0;s[i];i++) {
        if(s[i]==a) {
            return true;
        }

    }
    return false;
}

int solve(string s1,string s2) {

    int l1,l2;
    l1=s1.length();
    l2=s2.length();

    int dp[l1+1][l2+1];

    for(int i=0;i<=l1;i++) {
        dp[i][0]=0;
        dp[0][i]=0;
    }

    for(int i=1;i<=l1;i++) {
        for(int j=1;j<=l2;j++) {
            if(s1[i-1]==s2[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[l1][l2];



    
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s1,s2;
        cin>>s1>>s2;
        map<pair<string,string>,int> m;
        

        int ans=solve(s1,s2);
        cout<<ans<<endl;

    }

}