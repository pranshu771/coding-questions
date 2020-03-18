#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int *arr,int n,int k) {
    int *prefixSum=new int[n];
    for(int i=0;i<n;i++) {
        prefixSum[i]=0;
    }
    prefixSum[0]=arr[0];
    for(int i=1;i<n;i++) {
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }

    int maxIndex=-1;
    for(int i=n-1;i>=0;i--) {
        if(prefixSum[i]%k==0) {
            maxIndex=i;
            break;
        }
    }
    int maxlength=maxIndex+1;

    int index=maxIndex+1;
    int start=0;
    while(index<n) {
        if(index-start+1>maxlength) {
            if(start==0) {
                if(prefixSum[index]%k==0) {
                    maxlength=index+1;
                }
                else {
                    start++;
                }
            }
            else {
                if((prefixSum[index]-prefixSum[start-1])%k==0) {
                    maxlength=index-start+1;
                }
                else {
                    start++;
                }
            }
        }
        else {
            index++;
            start=0;
        }
    }
    

    return maxlength;
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