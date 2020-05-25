#include<bits/stdc++.h>
using namespace std;

bool checkBalanced(string s) {
    int count = 0;
    for (int i = 0;s[i];i++) {
        if(s[i]=='(') {
            count++;
        }
        else {
            count--;
        }

        if(count==-2 || count==2) {
            return false;
        }
    }

    if(count==0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        bool ans = checkBalanced(s);
        cout << ans << endl;
    }
}