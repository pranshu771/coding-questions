
#include<iostream>
using namespace std;
#include<bits/stdc++.h>



int ugly(int n) {
    int dp[n+1];
    dp[0]=-1;
    dp[1]=1;

    int i2,i3,i5;
    i2=1;
    i3=1;
    i5=1;
    int next2Multiple=2;
    int next3Multiple=3;
    int next5Multiple=5;

    for(int i=2;i<=n;i++) {
        dp[i]=min(next2Multiple,min(next3Multiple,next5Multiple));
        if(dp[i]==next2Multiple) {
            i2++;
            next2Multiple=dp[i2]*2;

        }
        if(dp[i]==next3Multiple) {
            i3++;
            next3Multiple=dp[i3]*3;
        }
        if(dp[i]==next5Multiple){
            i5++;
            next5Multiple=dp[i5]*5;
        }
    }

    return dp[n];

}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=ugly(n);
        cout<<ans<<endl;
    }
}