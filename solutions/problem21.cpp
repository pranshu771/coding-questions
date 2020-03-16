#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int inversionCount(int *arr,int n) {
    int count=0;
    int *altArray=new int[n];
    for(int i=0;i<n;i++) {
        altArray[i]=arr[i];
    }
    for(int i=0;i<n;i++) {
        
    }
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
        int ans=inversionCount(arr,n);
        cout<<ans<<endl;
    }
}