#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k) {
    if(n==0 || k>=n) {
        return 0;
    }

    if(k==0) {
        return 1;
    }

    return solve(n - 1, k - 1) * (n - k) + solve(n - 1, k) * (k + 1);
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin >> n >> k;

        int ans = solve(n, k);
        cout << ans << endl;
    }
}