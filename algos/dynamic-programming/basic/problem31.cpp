#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count(int m,int n,map<pair<int,int>,int> mp) {
    if(n==0) {
        return 1;
    }

    if(m<n) {
        return 0;
    }

    if(mp.find(make_pair(m,n))!=mp.end()) {
        return mp[make_pair(m,n)];
    }

    return mp[make_pair(m,n)]=count(m/2,n-1,mp)+count(m-1,n,mp);
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int m,n;
        cin>>m>>n;

        map<pair<int,int>,int> mp;

        int ans=count(m,n,mp);
        cout<<ans<<endl;
    }
}