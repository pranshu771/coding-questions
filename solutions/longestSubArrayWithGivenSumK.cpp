#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n,int k) {
    int maxLen=0;
    int curSum=0;
    int index=-1;
    unordered_map<int,int> hash;
    hash.insert(pair<int,int>(0,-1));
    for(int i=0;i<n;i++) {
        curSum+=arr[i];
        if(curSum==k) {
            maxLen=i+1;
        }

        if(hash.find(curSum)==hash.end()) {
            hash[curSum]=i;
        }

        if(hash.find(curSum-k)!=hash.end()) {
            index=hash[curSum-k];
            if(i-index>maxLen) {
                maxLen=i-index;
            }
        }


    }
    return maxLen;
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
            if(arr[i]==0) {
                arr[i]=-1;
            }
            else {
                arr[i]=1;
            }
        }
        int ans=solve(arr,n,0);
        cout<<ans<<endl;
    }
}