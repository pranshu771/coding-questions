//solution to problem2 brute force solution

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int *arr,int k,int n) {
    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=i;j<n;j++) {
            sum+=arr[j];
            if(sum<k) {

            }
            else if(sum==k) {
                cout<<i+1<<" "<<j+1;
                return ;
            }
            else {
                break;
            }
        }
    }
    cout<<-1;
    return ;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int sum;
        cin>>sum;
        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        solve(arr,sum,n);
        cout<<endl;
    }
}