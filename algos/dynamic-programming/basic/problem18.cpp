#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maximumCost(int *arr,int n,int len,map<int,int> m) {
    if(len<=0) {
        return 0;
    }
    
    int maximum=INT_MIN;

    if(m.find(len)!=m.end()) {
        maximum=max(maximum,m[len]);
    }

    for(int i=1;i<=len;i++) {
        maximum=max(maximum,arr[i-1] + maximumCost(arr,n,len-i,m));
    }

    return maximum;

    
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

        map<int,int> m;
        int ans=maximumCost(arr,n,n,m);
        cout<<ans<<endl;
    }
}