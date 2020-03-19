#include<iostream>
using namespace std;
#include<bits/stdc++.h>

pair<int,int> solve(int *arr,int n) {
    
int repeat,missing;

for(int i=0;i<n;i++) {
    
    if(arr[abs(arr[i])-1]>0) {
        arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
    }
    else {
        repeat=abs(arr[i]);
    }
}

for(int i=0;i<n;i++) {
    if(arr[i]>0) {
        missing=i+1;
        break;
    }
}

return make_pair(repeat,missing);
    
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

        pair<int,int>ans=solve(arr,n);
        cout<<ans.first<<" "<<ans.second<<" "<<endl;
    }
}