#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maximum(int *arr,int n) {
    int max=INT_MIN;
    for(int i=0;i<n;i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    return max;

}

int solution(int *arr,int n) {
    int max=maximum(arr,n);
    if(max<=0) {
        return max;
    }
    max=0;
    int curMax=0;
    for(int i=0;i<n;i++) {
        curMax+=arr[i];
        if(curMax<0) {
            curMax=0;
        }
        else {
            if(curMax>max) {
                max=curMax;
            }
        }


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
        int ans=solution(arr,n);
        cout<<ans<<endl;
    }
}