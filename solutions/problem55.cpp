#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n) {
    
    int *maxSum=new int[n];
    maxSum[0]=arr[0];
    maxSum[1]=max(arr[0],arr[1]);
    int maxnum=0;
    for(int i=2;i<n;i++) {
        if(maxSum[i-2]>maxnum) {
            maxnum=maxSum[i-2];
        }
        maxSum[i]=arr[i]+maxnum;
    }
    int maximum=INT_MIN;
    for(int i=0;i<n;i++) {
        if(maxSum[i]>maximum) {
            maximum=maxSum[i];
        }
    }

    return maximum;
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
        cout<<ans;
    }
}