#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int sum(int *arr,int n) {
    int a=0;
    for(int i=0;i<n;i++) {
        a+=arr[i];
    }
    return a;
}
int maximumSum(int *arr,int n) {
    int productSum=0;
    for(int i=0;i<n;i++) {
        productSum+=(i*arr[i]);
    }
    int count=1;
    int max=productSum;
    int s=sum(arr,n);
    while(count<n) {
        
        productSum=productSum+arr[count-1]-s+(arr[count-1])*(n-1);
        
        if(productSum>max) {
            max=productSum;
        }
        count++;
    }
    return max;
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
        int ans=maximumSum(arr,n);
        cout<<ans<<endl;
    }
}