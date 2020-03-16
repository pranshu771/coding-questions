#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int k,int n) {
    sort(arr,arr+n);

    int ans=arr[n-1]-arr[0];
    int small=arr[n-1]-k;
    int big=arr[0]+k;
    int add,subs;

    if(small>big) {
        int temp=small;
        small=big;
        big=temp;
    }

    int i=1;
    while(i<n) {
        subs=arr[i]-k;
        add=arr[i]+k;

        if(add<=big||subs>=small) {
            
        }
        else {
            if(big-subs<=add-small) {
                small=subs;
            }
            else {
                big=add;
            }
        }
        i++;
    }
    return min(ans,big-small);
    


}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int k,n;
        cin>>k;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int ans=solve(arr,k,n);
        cout<<ans<<endl;
    }
}