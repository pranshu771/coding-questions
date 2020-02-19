#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int *arr,int n) {
    pair<int,int> *p=new pair<int,int>[n];
    int max=arr[n-1];
    p[n-1].first=arr[n-1];
    p[n-1].second=0;
    for(int i=n-2;i>=0;i--) {
        p[i].first=arr[i];
        p[i].second=max;
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    for(int i=0;i<n;i++) {
        if(p[i].first>=p[i].second) {
            cout<<p[i].first<<" ";
        }
    }
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
        cout<<endl;
    }
}