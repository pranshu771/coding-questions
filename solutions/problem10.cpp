#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int *arr,int n) {
    int start=0;
    int end=0;
    bool bought=false;
    for(int i=1;i<n;i++) {
        if(arr[i]>arr[i-1]) {
            if(!bought) {
                start=i-1;
                bought=true;
            }
            else {
                
            }
            if(i==n-1) {
                end=i;
                cout<<"("<<start<<" "<<end<<") ";
                bought=false;
            }
        }
        else {
            if(bought) {
                end=i-1;
                cout<<"("<<start<<" "<<end<<") ";
                bought=false;
            }
        }
    }
    if(start==0&&end==0) {
        cout<<"No Profit";
    }
    
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
        solve(arr,n);
        cout<<endl;
    }
}