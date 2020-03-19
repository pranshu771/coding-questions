#include<iostream>
using namespace std;
#include<bits/stdc++.h>
long long* solve(long long *arr,long long n) {
    long long maxIndex=n-1;
    long long minIndex=0;
    long long maxElement=arr[n-1]+1;

    for(long long i=0;i<n;i++) {
        if(i%2==0) {
            arr[i]+=(arr[maxIndex]%maxElement)*maxElement;
            maxIndex--;
        }
        else {
            arr[i]+=(arr[minIndex]%maxElement)*maxElement;
            minIndex++;
        }
    }

    for(long long i=0;i<n;i++) {
        arr[i]=arr[i]/maxElement;
    }
    return arr;
}

int main() {

    int t;
    cin>>t;

    while(t--) {
        long long n;
        cin>>n;

        long long *arr=new long long[n];
        for(long long i=0;i<n;i++) {
            cin>>arr[i];
        }

        arr=solve(arr,n);

        for(long long i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}