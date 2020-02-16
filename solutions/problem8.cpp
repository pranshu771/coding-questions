#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int *dep,int n) {
    sort(arr,arr+n);
    sort(dep,dep+n);

    int res,plt,i=1;
    int j=0;
    while(i<n&&j<n) {
        if(arr[i]<=dep[j]) {
            plt++;
            i++;
            res=max(res,plt);
        }
        else {
            plt--;
            j++;
        }
    }
    return res;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int *arr1=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr1[i];
        }
        int *arr2=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr2[i];
        }
        int ans=solve(arr1,arr2,n);
        cout<<ans<<endl;

    }
}