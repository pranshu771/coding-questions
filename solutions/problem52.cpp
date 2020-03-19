#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n,int k) {
    sort(arr,arr+n);

    int i=0;
    int j=1;
    while(j<n) {
        if(arr[j]-arr[i]==k) {
            return 1;
        }
        else if(arr[j]-arr[i]>k) {
            i++;
        }
        else {
            j++;
        }
    }
    return -1;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        int ans=solve(arr,n,k);
        cout<<ans<<endl;
    }
}