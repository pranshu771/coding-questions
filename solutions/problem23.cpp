
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(int *arr,int n) {
    int z=0;
    int o=0;
    int t=0;
    for(int i=0;i<n;i++) {
        if(arr[i]==0) {
            z++;
        }
        else if(arr[i]==1) {
            o++;
        }
        else {
            t++;
        }

    }
    for(int i=0;i<z;i++) {
        cout<<0<<" ";
        
    }
    for(int i=0;i<o;i++) {
        cout<<1<<" ";
        
    }
    for(int i=0;i<t;i++) {
        cout<<2<<" ";
        
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}