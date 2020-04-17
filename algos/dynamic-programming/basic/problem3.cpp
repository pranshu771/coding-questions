#include<iostream>
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int; 
using namespace std;

cpp_int catalan(int n) {
    cpp_int dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++) {
        cpp_int res=0;
        for(int j=0;j<i;j++) {
            res+=(dp[j]*dp[i-j-1]);
        }
        dp[i]=res;
    }

    return dp[n];
    
    
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        cpp_int ans=catalan(n);
        cout<<ans<<endl;
    }
}