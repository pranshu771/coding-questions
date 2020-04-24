#include<bits/stdc++.h>
using namespace std;

int LISBeforePrefix(int *arr,int n,int p,int k) {
    int size=p+2;
    int dp[size]={0};
    memset(dp,0,sizeof(dp));

    
    if(arr[k]>arr[0]) {
        dp[0]=arr[0]+arr[k];
    }
    else {
        dp[0]=arr[k];
    }

    for(int i=1;i<=p;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i]<arr[k]&&arr[i]>arr[j]) {
                dp[i]=max(dp[j]+arr[i],dp[i]);
            } 
        }
    }

    int maximum=INT_MIN;
    for(int i=0;i<size;i++) {
        maximum=max(maximum,dp[i]);
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

        int prefixIndex;
        cin>>prefixIndex;
        int KthIndex;
        cin>>KthIndex;

        int ans=LISBeforePrefix(arr,n,prefixIndex,KthIndex);
        cout<<ans<<endl;
    }
}