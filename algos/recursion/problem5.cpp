//Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int summation(int *arr,int n) {
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
    return sum;
}

bool solve(int *arr,int n,int sum1,int sum2,int start) {
    if(sum1==sum2) {
        return true;
    }
    if(sum1<sum2) {
        return false;
    }
    if(start>=n) {
        return false;
    }

    for(int i=start;i<n;i++) {
        return solve(arr,n,sum1-arr[i],sum2+arr[i],i+1) || solve(arr,n,sum1,sum2,i+1);
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

        int sum=summation(arr,n);

        if(solve(arr,n,sum,0,0)) {
            cout<<"YES";
        }
        else {
            cout<<"NO";
        }
        cout<<endl;
    }
}