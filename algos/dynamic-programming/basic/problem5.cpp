#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int; 
#define M 1000000007

long long int solve(int n,int r) {
    long long int dp[r+1]={1};
    dp[0]=1;

    for(int i=1;i<=r;i++) 
        dp[i]=(dp[i-1]*(n-i+1)/i);

        dp[i]=((dp[i-1]%M)*((n-i+1)%M)*(inverse(i)%M))%M;
    return dp[r]%M;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,r;
        cin>>n>>r;

        long long int ans=solve(n,r);
        cout<<ans<<endl;
    }
}