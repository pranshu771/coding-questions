#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int k,int n) {
    int count=0;
    int index=-1;
    int bad=0;
    for(int i=0;i<n;i++) {
        if(arr[i]<=k) {
            if(count==0) {
                index=i;
            }
            count++;
        }
    }
    for(int i=index;i<index+count;i++) {
        if(arr[i]>k) {
            bad++;
        }
    }
    return bad;
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
        int ans=solve(arr,k,n);
        cout<<ans<<endl;
    }
}