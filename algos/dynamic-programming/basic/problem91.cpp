#include<bits/stdc++.h>
using namespace std;

int countPaths(int m,int n) {
    if(m==0 || n==0) {
        return 1;
    }
    return countPaths(m - 1, n) + countPaths(m, n - 1);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int m, n;
        cin >> m >> n;

        int ans = countPaths(m-1, n-1);
        cout << ans << endl;

    }
}