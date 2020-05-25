#include<bits/stdc++.h>
using namespace std;

map<string,bool> m;

bool solve(string s) {
    if(m.find(s)!=m.end()) {
        return true;
    }
    int l = s.length();
    for (int i = 1; i <= l;i++) {
        if(m.find(s.substr(0,i))!=m.end()&&solve(s.substr(i,l-i))) {
            return true;
        }
    }
    return false;
}

int main()
{

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            m[a] = true;
        }
        string str;
        cin >> str;

        bool ans = solve(str);

        cout << ans << endl;
    }
}