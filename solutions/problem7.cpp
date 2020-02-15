#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int n,int m) {
    int sum=n*(n+1)/2;
    int left = m%sum;
    for(int i=1;i<=n&&left>0;i++) {
        left=left-i;
        if(left<0) {
            return left+i;
        }
    }
    return left;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int m;
        cin>>m;
        int ans=solve(n,m);
        cout<<ans<<endl;
    }
}