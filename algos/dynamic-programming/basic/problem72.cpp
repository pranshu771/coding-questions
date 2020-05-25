#include<bits/stdc++.h>
using namespace std;

int minDeletions(string s,int start,int end) {
    int l = end - start + 1;
    int dp[l + 1][l + 1];

    for (int i = 0; i <= l;i++) {
        for (int j = 0; j <= l;j++) {
            
        }
    }
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int l;
        cin>>l;

        string s;
        cin>>s;

        int ans=minDeletions(s,0,l-1);
        cout << ans << endl;

    }
}