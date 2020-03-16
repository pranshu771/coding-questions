#include <iostream>
using namespace std;
#include<bits/stdc++.h>



int solve(int *arr,int k,int n) {
    
    int sum=0;
    for(int i=0;i<k;i++) {
        sum+=arr[i];
    }

    int result=sum;
    int minimum=INT_MAX;
    int cursum=0;
    for(int i=k;i<n;i++) {
        sum+=arr[i];
        result=max(result,sum);
        cursum+=arr[i-k];
        minimum=min(minimum,cursum);
        result=max(result,sum-minimum);

    }
    return result;
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
        int k;
        cin>>k;
        int ans=solve(arr,k,n);
        cout<<ans<<endl;
    }
}