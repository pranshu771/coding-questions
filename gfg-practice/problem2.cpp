using namespace std; 
#include<bits/stdc++.h>

bool isPallindrome(string s) {
    int start = 0;
    int end = s.length() - 1;

    while(start<end) {
        if(s[start]!=s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool solve(string s,int k) {
    if(s[0]=='\0') {
        return true;
    }
    if(k==0) {
        return isPallindrome(s);
    }
    if(s[0]!=s[s.length()-1]) {
        return solve(s.substr(0, s.length() - 1), k - 1) || solve(s.substr(1, s.length() - 1), k - 1);
    }
    else {
        return solve(s.substr(1,s.length()-2),k);
    }
    
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin>>s;
        int k;
        cin >> k;

        bool ans = solve(s, k);
        cout << ans << endl;
    }
}