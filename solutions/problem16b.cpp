//Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa. Order of elements in output doesn’t matter. Extra positive or negative elements should be moved to end.
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(int *arr,int n) {
    int *temp=new int[n];
    int j=0;
    for(int i=0;i<n;i++) {
        if(arr[i]>=0) {
            temp[j++]=arr[i];
        }
    }
    for(int i=0;i<n;i++) {
        if(arr[i]<0) {
            temp[j++]=arr[i];
        }
    }
    int neg=0;
    for(int i=0;i<n;i++) {
        if(temp[i]<0) {
            neg=i;
            break;
        }
    }
    int k=0;
    if(arr[0]<0) {
        while(neg<n) {
            if(k%2==0) {
                int a=temp[k];
                temp[k]=temp[neg];
                temp[neg]=a;
            }
            k+=2;
            neg++;
        }
    }
    else {
        k=1;
        while(neg<n) {
            if(k%2==1) {
                int a=temp[k];
                temp[k]=temp[neg];
                temp[neg]=a;
            }
            k+=2;
            neg++;
        }
    }
    

    //print temp array
    for(int i=0;i<n;i++) {
        cout<<temp[i]<<" ";
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
        solve(arr,n);
        cout<<endl;
    }
}