using namespace std; 
#include<bits/stdc++.h>

int solve(int n) {
    int ops = 0;
    while (n != 0)
    {
        if(n%2!=0) {
            n--;
        }
        else {
            n /= 2;
        }
        ops++;
    }
    return ops;
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