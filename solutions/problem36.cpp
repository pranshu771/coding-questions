#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n) {
    
    int ans=-1;

    for(int i=0;i<n;i++) {
        int start=i;
        int end=n-1;

        if(end-start<=ans) {
            return ans;
        }

        while(start<end) {
            if(arr[start]<=arr[end]) {
                if(end-start>ans) {
                    ans=end-start;
                }
                break;
            }
            end--;
        }
        

    }
    return ans;
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