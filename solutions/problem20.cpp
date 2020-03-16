#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maximumProduct(int *arr,int n) {
    int globalmax=arr[0];
    int curmax=arr[0];
    int curmin=arr[0];

    for(int i=1;i<n;i++) {
        if(arr[i]==0) {
            curmax=0;
        }
        else {
            if(curmax==0) {
                curmax=arr[i];
                curmin=arr[i];
            }
            else {
                int temp=curmax;
                curmax=max({arr[i]*curmax,curmin*arr[i]});
                curmin=min({arr[i]*curmin,arr[i]*temp});
            }
        }
        
        if(curmax>globalmax) {
            globalmax=curmax;
        }
    }
    return globalmax;
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
        int ans=maximumProduct(arr,n);
        cout<<ans<<endl;
    }
}