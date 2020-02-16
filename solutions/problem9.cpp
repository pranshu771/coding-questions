#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> leftLarge(int *arr,int i,int n) {
    
    int num=10000;
    int index;
    for(int j=0;j<i;j++) {
        if(arr[j]>arr[i]) {
            num=min(num,arr[j]);
            index=j;
        }
    }
    return make_pair(num,index);
}

pair<int,int> rightLarge(int *arr,int i,int n) {
    int num=10000;
    int index;
    for(int j=i+1;j<n;j++) {
        if(arr[j]>arr[i]) {
            num=min(num,arr[j]);
            index=j;
        }
    }
    return make_pair(num,index);
}
int sum(int *arr,int n) {
    int ans=0;
    for(int i=0;i<n;i++) {
        ans+=arr[i];
    }
    return ans;
}

int solve(int *arr,int n) {
    pair<int,int> *p=new pair<int,int>[n];
    int i=0;
    int j=n-1;
    int rightMax=0;
    int leftMax=0;
    p[0].first=0;
    p[n-1].second=0;
    while(i<n-1&&j>0) {
        leftMax=max(arr[i],leftMax);
        p[i+1].first=leftMax;
        rightMax=max(arr[j],rightMax);
        p[j-1].second=rightMax;
        i++;
        j--;

    }
    int res=0;
    for(int i=0;i<n;i++) {
        if(min(p[i].first,p[i].second)>arr[i]) {
            res+=min(p[i].first,p[i].second)-arr[i];
        }
        //cout<<p[i].first<<" "<<p[i].second<<endl;
        
    }
    return res;
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