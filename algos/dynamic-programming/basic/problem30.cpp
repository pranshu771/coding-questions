#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count(int n,int diff,map<pair<int,int>,int> m) {
    if(abs(diff)>n) {
        return 0;
    }

    if(n==1&&diff==0) {
        return 2;
    }

    if(n==1&&abs(diff)==1) {
        return 1;
    }

    if(m.find(make_pair(n,diff))!=m.end()) {
        return m[make_pair(n,diff)];
    }

    //return 2*count(n-1,diff)+count(n-1,diff+1)+count(n-1,diff-1,m);
    return m[make_pair(n,diff)] = 2*count(n-1,diff,m) + count(n-1,diff-1,m) + count(n-1,diff+1,m); 
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        map<pair<int,int>,int> m;

        int ans=count(n,0,m);
        cout<<ans<<endl;

    }
}