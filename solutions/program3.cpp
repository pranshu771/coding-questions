//Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a p

#include<iostream>
using namespace std;

int findSum(int *arr,int start,int end,int n) {
    if(start<0) {
        return -1;
    }
    else if(end>=n) {
        return -1;
    }
    else {
        return arr[end]-arr[start-1];
    }
}
int solve(int *arr,int n) {
    int num=0;
    for(int i=0;i<n;i++) {
        arr[i]+=num;
        num=arr[i];
    }
    for(int i=0;i<n;i++) {
        if(findSum(arr,0,i-1,n)==findSum(arr,i+1,n-1,n)) {
            if(findSum(arr,0,i-1,n)==-1) {
                return 0;
            }
            else {
                return i+1;
            }
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