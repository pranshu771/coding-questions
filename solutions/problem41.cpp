#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int mergeCount(int *arr,int n) {

    int start=0;
    int end=n-1;
    int merge=0;

    while(start<end) {
        if(arr[start]==arr[end]) {
            start++;
            end--;
        }
        else if(arr[start]<arr[end]) {
            arr[start+1]=arr[start]+arr[start+1];
            arr++;
            merge++;
            n--;
            end--;
        }
        else {
            arr[end-1]=arr[end]+arr[end-1];
            merge++;
            n--;
            end--;
        }

    }
    return merge;
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

        int ans=mergeCount(arr,n);
        cout<<ans<<endl;
    }
}