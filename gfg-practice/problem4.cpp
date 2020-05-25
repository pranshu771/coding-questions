using namespace std; 
#include<bits/stdc++.h>
#define MAX_SIZE 1000000;

unordered_map<pair<string, int>, bool> m;

bool isPallindrome(string s) {
    int start = 0;
    int end = s.length() - 1;
    while(start<end) {
        if(s[start]!=s[end]) {
            return false;
        }
    }
    return true;
}

bool solve(string s,int k) {
    if(k==0) {
        return isPallindrome(s);
    }
    if(s[0]=='\0') {
        return true;
    }

    if(m.find(make_pair(s,k))!=m.end()) {
        return m[make_pair(s, k)];
    }
    if(s[0]==s[s.length()-1]) {
        m[make_pair(s, k)] = solve(s.substr(1, s.length() - 2), k);
        return m[make_pair(s, k)];
    }
    else {
        m[make_pair(s, k)] = solve(s.substr(0, s.length() - 1), k - 1) || solve(s.substr(1, s.length() - 1), k - 1);
        return m[make_pair(s, k)];
    }
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin>>s;

        int k;
        cin>>k;

        bool ans = solve(s, k);
    }
}
