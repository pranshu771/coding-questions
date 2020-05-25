#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include<gmp.h>

void solve(int n) {
    if(n==1) {
        cout << 1;
        return;
    }
    if(n==2) {
        cout << 1;
        return;
    }
    long long int a = 1;
    long long int b = 1;
    long long int c;

    for (int i = 3; i <= n;i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        solve(n);
        cout << endl;
    }
}