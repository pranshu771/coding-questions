#include<iostream>
using namespace std;
#include<bits/stdc++.h>



bool solve(int *arr,int n,int k) {
    sort(arr,arr+n);
    for(int i=0;i<n;i++) {
        if(binary_search(arr+i+1,arr+n,arr[i]+k)) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int *arr=new int[n];
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        bool ans=solve(arr,n,k);
        if(ans) {
            cout<<1<<endl;
        }
        else {
            cout<<-1<<endl;
        }
        

    }
}