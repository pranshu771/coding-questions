//Given an array of integers and a number K. Write a program to find the maximum sum of a subarray of size K.
#include<iostream>
using namespace std;

int sum(int *arr,int n,int k) {
    int sum=0;
    for(int i=0;i<k;i++) {
        sum+=arr[i];
    }
    int start=0;
    int end=k;
    int max=sum;
    while(end<n) {
        sum=sum-arr[start];
        sum=sum+arr[end];
        if(sum>max) {
            max=sum;
        }
        start++;
        end++;
    } 
    return max;

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
        int ans=sum(arr,n,k);
        cout<<ans<<endl;
    }
}