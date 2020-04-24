#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n) {

    int x=arr[0];
    int y=arr[0]+arr[1];
    int z=max(y,arr[1]+arr[2]);

    for(int i=3;i<n;i++) {
        int oldz=z;
        z=max(z,max(y+arr[i],x+arr[i]+arr[i-1]));
        int oldy=y;
        y=oldz;
        x=oldy;
    }

    return max(x,(max(y,z)));
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
        cout<<ans<<endl;
    }
}