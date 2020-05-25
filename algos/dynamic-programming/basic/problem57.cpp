#include<bits/stdc++.h>
using namespace std;

int solve(int n) {

    if(n==0) {
        return 0;
    }
    if(n==1) {
        return 1;
    }

    return max(n,solve(n/5)+solve(n/4)+solve(n/3)+solve(n/2));
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        int ans=solve(n);
        cout<<ans<<endl;
    }
}