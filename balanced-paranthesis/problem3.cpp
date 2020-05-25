#include<bits/stdc++.h>
using namespace std;

int solve(string s,int n) {
    if(s.length()==1&&n==2) {
        return 1;
    }
    if(n==0) {
        return 3;
    }
    if(n==1) {
        return s.length() + 1;
    }

    return solve(s.substr(0, s.length() - 1), 2) + solve(s.substr(0, s.length() - 1), 1) + solve(s.substr(0, s.length() - 1),0);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int k = 1;
        cin >> k;

        int ans = solve(s,k);
        cout << ans << endl;
    }
}