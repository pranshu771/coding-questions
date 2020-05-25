#include<bits/stdc++.h>
using namespace std;

bool check(string s,int i,int j) {
    if(s[i]=='('&&s[j]==')') {
        return true;
    }
    if(s[i]=='?'&&s[j]==')') {
        return true;
    }
    if(s[i]=='('&&s[j]=='?') {
        return true;
    }

    if(s[i]=='{'&&s[j]=='}') {
        return true;
    }
    if(s[i]=='?'&&s[j]=='}') {
        return true;
    }
    if(s[i]=='{'&&s[j]=='?') {
        return true;
    }

    if(s[i]=='['&&s[j]==']') {
        return true;
    }
    if(s[i]=='?'&&s[j]==']') {
        return true;
    }
    if(s[i]=='['&&s[j]=='?') {
        return true;
    }

    return false;

}

int count(string s,int start,int end) {
    int sum = 0;
    if(start>end) {
        return 1;
    }

    for (int i = start + 1; i <= end;i+=2) {
        if(check(s,start,i)) {
            sum += count(s, start + 1, i - 1) * count(s, i + 1, end);
        }
        else if(s[start]=='?'&&s[i]=='?') {
            sum += count(s, start + 1, i - 1) * count(s, i + 1, end) * 3;
        }
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int ans = count(s,0,s.length()-1);
        cout << ans << endl;
    }
}