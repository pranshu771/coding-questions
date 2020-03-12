#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(int *arr,int n) {
    vector<int> v1;
    vector<int> v2;
    vector<int> out;
    for(int i=0;i<n;i++) {
        if(arr[i]>=0) {
            v1.push_back(arr[i]);
        }
        else {
            v2.push_back(arr[i]);
        }
    }
    // for(int i=0;i<v1.size();i++) {
    //     cout<<v1[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<v2.size();i++) {
    //     cout<<v2[i]<<" ";
    // }
    
    int count=0;
    int i1=0;
    int i2=0;
    if(arr[0]>=0) {
        while(i1<v1.size()&&i2<v2.size()) {
            if(count%2==0) {
                out.push_back(v1[i1]);
                i1++;
            }
            else {
                out.push_back(v2[i2]);
                i2++;
            }
            count++;
        }
        if(i1<v1.size()) {
            while(i1<v1.size()) {
                out.push_back(v1[i1]);
                i1++;
            }
        }
        if(i2<v2.size()) {
            while(i2<v2.size()) {
                out.push_back(v2[i2]);
                i2++;
            }
        }
    }
    else {
        while(i1<v1.size()&&i2<v2.size()) {
            if(count%2==1) {
                out.push_back(v1[i1]);
                i1++;
            }
            else {
                out.push_back(v2[i2]);
                i2++;
            }
            count++;
        }
        if(i1<v1.size()) {
            while(i1<v1.size()) {
                out.push_back(v1[i1]);
                i1++;
            }
        }
        if(i2<v2.size()) {
            while(i2<v2.size()) {
                out.push_back(v2[i2]);
                i2++;
            }
        }
    }
    
    for(int i=0;i<out.size();i++) {
        cout<<out[i]<<" ";
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