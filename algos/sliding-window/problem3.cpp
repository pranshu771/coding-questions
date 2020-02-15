#include<iostream>
using namespace std;

int solve(int n,int *arr1,int *arr2) {
    int num=0;
    for(int i=0;i<n;i++) {
        arr1[i]=arr1[i]+num;
        num=arr1[i];
    }
    num=0;
    for(int i=0;i<n;i++) {
        arr2[i]=arr2[i]+num;
        num=arr2[i];
    }
    int start=0;
    int end=n-1;
    int sum1,sum2;
    int diff1,diff2;
    int prevDiff=-23;
    int curDiff=-45;
    while(start<=end) {
        if(start==0) {
            sum1=arr1[end];
            sum2=arr2[end];
        }
        else {
            sum1=arr1[end]-arr1[start-1];
            sum2=arr2[end]-arr2[start-1];
        }
        if(sum1==sum2) {
            cout<<start<<" "<<end<<endl;
            return end-start+1;
        }
        else if(sum2>sum1) {
            curDiff=sum2-sum1;
            if(curDiff==prevDiff) {
                start++;
                end++;
            }
            else {
                end--;
            }
        }
        else {
            curDiff=sum1-sum2;
            if(curDiff==prevDiff) {
                start++;
                end++;
            }
            else {
                end--;
            }
        }
        prevDiff=curDiff;
    }
    
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int *arr1=new int[n];
        int *arr2=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++) {
            cin>>arr2[i];
        }
        int ans=solve(n,arr1,arr2);
        cout<<ans<<endl;
    }
}