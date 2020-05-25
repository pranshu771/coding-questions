#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1,string s2,int l1,int l2) {
    int i = 0;
    int length = 0;
    int res = INT_MIN;
    int j = 0;
    while (s1[i])
    {
        
        while(s1[i]!=s2[j]&&s2[j]) {
            j++;
        }
        
        length = 0;
        int it = i;
        while (s2[j] && s1[it] && s1[it] == s2[j])
        {
            length++;
            it++;
            j++;
        }
        if(j==l2) {
            i++;
            j = 0;
        }

        res = max(res, length);
    }
    return res;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int l1, l2;
        cin >> l1 >> l2;
        string s1,s2;
        cin >> s1 >> s2;
        int ans = longestCommonSubstring(s1, s2, l1, l2);
        cout << ans << endl;
    }
}