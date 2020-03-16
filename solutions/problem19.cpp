#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n) {
    
    for(int i=0;i<n;i++) {
        if(arr[i]==0) {
            arr[i]=-1;
        } 
    }
    
    int maximum=0;
    int curSum=0;
    int index=0;
    unordered_map<int,int> hash;
    hash.insert(make_pair(0,-1));
    
    for(int i=0;i<n;i++) {
        curSum+=arr[i];
        if(arr[i]==0) {
            maximum=i+1;
        }
        
        if(hash.find(curSum)==hash.end()) {
            hash[curSum]=i;
        }
        
        if(hash.find(curSum)!=hash.end()) {
            index=hash[curSum];
            if(i-index>maximum) {
                maximum=i-index;
            }
        }
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
        int ans=maxLengthBitonicArray(arr,n);
        cout<<ans<<endl;
    }
}