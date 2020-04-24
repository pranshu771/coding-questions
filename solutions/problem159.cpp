#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void print(vector<int> v) {
    int size=v.size();
    cout<<"(";
    for(int i=0;i<size;i++) {
        if(i==size-1) {
            cout<<v[i];
            break;

        }
        cout<<v[i]<<" ";
    }
    cout<<")";
}

void solve(vector<int> v,int n,int i,int k,vector<int> out) {
    if(k<0) {
        return ;
    }
    if(k==0) {
        print(out);
        return ;
    }

    
    
    while(i<n) {
        out.push_back(v[i]);
        solve(v,n,i,k-v[i],out);
        out.pop_back();
        i++;
        
    }
    return ;

    
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        int k;
        cin>>k;

        sort(v.begin(),v.end());
        vector<int>::iterator ip;
        ip=unique(v.begin(),v.begin()+n);
        v.resize(distance(v.begin(),ip));

        vector<int> out;
        cout<<v.size();
        //solve(v,v.size(),0,k,out);
        cout<<endl;



        
        
    }
}