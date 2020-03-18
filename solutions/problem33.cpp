#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n) {
    int res=1;
    for(int i=0;i<n;arr[i]<=res;i++) {
        res+=arr[i];
    }
    return res;
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

        int ans=solve(arr,n);

    }

}