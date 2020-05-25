#include<bits/stdc++.h>
using namespace std;

bool check(string s1,string s2) {
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; s1[i];i++) {
        if(s1[i]=='(') {
            count1++;
        }
        else {
            count1--;
        }
    }

    for (int i = 0; s2[i];i++) {
        if(s2[i]=='(') {
            count2++;
        }
        else {
            count2--;
        }
    }

    return count1 + count2 == 0;
}

int solve(vector<string> v) {
    int n = v.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n;j++) {
            if(check(v[i],v[j])) {
                count++;
            }
        }
    }
    return count;
}

    int main()
{
    int t;
    cin >> t;

    while(t--) {
        
        int n;
        cin >> n;

        vector<string> v(n);
        string s;

        for (int i = 0; i < n;i++) {
            cin >> v[i];
        }

        int ans = solve(v);
        cout << ans << endl;
    }
}