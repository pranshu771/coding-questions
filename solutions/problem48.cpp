#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n) {

    int min=INT_MAX;
    int max=INT_MIN;

    for(int i=0;i<n;i++) {
        if(arr[i]<min) {
            min=arr[i];
        }
        else if(arr[i]>max) {
            max=arr[i];
        }
        else {

        }
    }

    int size;
    if(max>min) {
        size=max-min+1;
    }
    else {
        size=0;
    }
    int *freq=new int[size];
    
    for(int i=0;i<size;i++) {
        freq[i]=0;
    }
    
    for(int i=0;i<n;i++) {
        freq[arr[i]-min]++;
    }
    
    for(int i=0;i<size;i++) {
        if(freq[i]>n/2) {
            return i+min;
        }
    }
    return -1;
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