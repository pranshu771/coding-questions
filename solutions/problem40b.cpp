//This is optimized version of problem40

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n,int k) {

    int *prefixArray=new int[n];
    int sum=0;

    for(int i=0;i<n;i++) {
        sum+=arr[i];
        prefixArray[i]=((sum%k)+k)%k;
    }

    unordered_map<int,int> m;

    int maxLength=0;
    for(int i=0;i<n;i++) {
        if(prefixArray[i]==0) {
            maxLength=i+1;
        }
        else if(m.find(prefixArray[i])==m.end()) {
                m[prefixArray[i]]=i;
        }
        else {
            if(i-m[prefixArray[i]]>maxLength) {
                maxLength=i-m[prefixArray[i]];
            }
        }
        
    }

    return maxLength;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        int ans=solve(arr,n,k);
        cout<<ans<<endl;
    }

}