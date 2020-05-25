#include<bits/stdc++.h>
using namespace std;

int maximumDiff(string s) {
    int l=s.length();
    int dp[l]={0};
    memset(dp,0,sizeof(dp));
    dp[0]=(s[0]=='0')?1:-1;
    


    for(int i=1;i<l;i++) {
        if(s[i]=='1') {
            dp[i]=dp[i-1]-1;
        }
        else {
            if(dp[i-1]<0) {
                dp[i]=1;
            }
            else {
                dp[i]=dp[i-1]+1;
            }
        }
    }

    int maximum=INT_MIN;
    for(int i=0;i<l;i++) {
        maximum=max(maximum,dp[i]);
    }
    return maximum;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int ans=maximumDiff(s);
        cout<<ans<<endl;
    }
}