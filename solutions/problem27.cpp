#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maxDifference(int *arr,int n) {
    int min=arr[0];
    int max=arr[0];
    int i=1;
    int profit=-1;
    while(i<n) {
        if(arr[i]<min) {
            min=arr[i];
            max=arr[i];
        }
        else if(arr[i]>max) {
            max=arr[i];
        }
        else {

        }
        if(max-min>profit&&max!=min) {
            profit=max-min;
        }
        i++;
    }
    return profit;
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
        int ans=maxDifference(arr,n);
        cout<<ans<<endl;
    }
}