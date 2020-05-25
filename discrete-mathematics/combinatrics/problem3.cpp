#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    if(n==0) {
        return 1;
    }
    if(n<0) {
        return 0;
    }

    return solve(n - 1) + solve(n - 2);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int ans = solve(n);
        cout << ans << endl;
    }
}