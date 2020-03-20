#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long



int main() {
    int t;
    cin>>t;
    
    while(t--) {
        ll n1,n2,n3;
        cin>>n1>>n2>>n3;
        
        map<ll,int> m;
        int x;
        
        for(int i=0;i<n1;i++) {
            cin>>x;
            if(m[x]==0) {
                m[x]=1;
            }
        }
        for(int i=0;i<n2;i++) {
            cin>>x;
            if(m[x]==1) {
                m[x]=2;
            }
        }
        
        for(int i=0;i<n3;i++) {
            cin>>x;
            if(m[x]==2) {
                m[x]=3;
            }
        }
        int check=0;
        for(auto it=m.begin();it!=m.end();it++) {
            if(it->second==3) {
                cout<<it->first<<" ";
                check++;
            }
        }
        if(check==0) {
            cout<<-1;
        }
        cout<<endl;
        
    }
}