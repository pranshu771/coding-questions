#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m) {
    if(n==0) {
        return 1;
    }
    if(n<0) {
        return 0;
    }
    return solve(n - 1, m) + solve(n - m, m);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int m;
        cin >> m;

        int ans = solve(n, m);
        cout << ans << endl;
    }
}