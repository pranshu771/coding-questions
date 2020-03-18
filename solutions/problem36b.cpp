//solving problem36 with O(n)

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *ans,int n) {
    int *Lmin=new int[n];
    int *Rmax=new int[n];

    Lmin[0]=arr[0];
    for(int i=1;i<n;i++) {
        Lmin[i]=min(arr[i],Lmin[i-1]);
    }
    Rmax[n-1]=arr[n-1];
    for(int j=n-2;j>=0;j--) {
        Rmax[i]=max(arr[i],Rmax[i+1]);
    }

    int i=0;
    int j=0;
    int maxDiff=0;

    while(i<n&&j<n) {
        if(Lmin[i]<=Rmax[j]) {
            maxDiff=max(maxDiff,j-i);
            j++;
        }
        else {
            i++;
        }
    } 
    return maxDiff;
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