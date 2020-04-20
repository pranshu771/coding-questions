#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countProductLessThanK(int *arr,int n,int k) {

    if(k<=0) {
        return 0;
    }
    if(n==1) {
        if(arr[0]<=k) {
            return 1;
        }
        return 0;
    }

    int ans=countProductLessThanK(arr,n-1,k);

    if(arr[n-1]<=k&&arr[n-1]>0) {
        ans+=countProductLessThanK(arr,n-1,k/arr[n-1])+1;
    }
    return ans;
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

        int k;
        cin>>k;

        int ans=countProductLessThanK(arr,n,k);
        cout<<ans<<endl;
    }
}