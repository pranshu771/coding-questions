#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007



  

long long int nCr(int n,int r) {
    int dp[r+1];
    dp[0]=1;

    for(int i=1;i<=r;i++) {
        dp[i]=((dp[i-1]%M)*((n+1-i)%M)/i)%M;
    }
    return dp[r]%M;
}

long long int count(int n) {

    return nCr(2*n,n)%M;
    
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        map<pair<int,int>,int> m;

        long long int ans=count(n);
        cout<<ans<<endl;

    }
}