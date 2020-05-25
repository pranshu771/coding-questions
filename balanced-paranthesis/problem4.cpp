#include<bits/stdc++.h>
using namespace std;

int countReversals(string s) {
    int count = 0;
    int rev = 0;
    int open = 0;
    int closed = 0;

    for (int i = 0; s[i];i++) {
        if(s[i]=='{') {
            count++;
        }
        else {
            count--;
        }

        if(count==-1) {
            rev++;
            count = 1;
        }
    }
    if(count%2==0) {
        rev += count / 2;
    }
    else {
        rev = -1;
    }
    return rev;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int ans = countReversals(s);
        cout << ans << endl;
    }
}