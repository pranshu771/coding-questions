#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(int *arr,int n,int k,int q,int *queries) {
    for(int i=0;i<2*q;i+=2) {
        int l=queries[i];
        int r=queries[i+1];
        int size=0;

        if(r>l) {
            size=r-l+1;
        }
        

        int *out=new int[size];
        for(int i=0;i<size;i++) {
            out[i]=0;
        }
        

        for(int i=0;i<n;i++) {
            if(arr[i]>=l&&arr[i]<=r) {
                out[arr[i]-l]++;
            }
        }

        int count=0;
        for(int i=0;i<size;i++) {
            if(out[i]>=k) {
                count++;
            }
            
        }
        
        cout<<count<<" ";

    }
    cout<<endl;
    
} 

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,q,k;
        cin>>n>>q>>k;

        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        int *queries=new int[2*q];
        for(int i=0;i<2*q;i++) {
            cin>>queries[i];
        }

        solve(arr,n,k,q,queries);

    }
}