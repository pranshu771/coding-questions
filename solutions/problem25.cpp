#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maximumProfit(int *arr,int n) {
    int min=arr[0];
    int max=arr[0];
    int p=0;
    int profit[2]={0,0};

    int i=1;

    while(i<n) {
        if(arr[i]<min) {
            p=max-min;
            if(p<profit[0]&&p<profit[1]) {

            }
            else if(p>profit[0]&&p<profit[1]) {
                profit[0]=p;
            }
            else if(p<profit[0]&&p>profit[1]) {
                profit[1]=p;
            }
            else {
                if(profit[0]<profit[1]) {
                    profit[0]=p;
                }
                else {
                    profit[1]=p;
                }
            }
            min=arr[i];
            max=arr[i];
        }
        else if(arr[i]>max) {
            max=arr[i];
        }
        else {
            p=max-min;
            if(p<profit[0]&&p<profit[1]) {

            }
            else if(p>profit[0]&&p<profit[1]) {
                profit[0]=p;
            }
            else if(p<profit[0]&&p>profit[1]) {
                profit[1]=p;
            }
            else {
                if(profit[0]<profit[1]) {
                    profit[0]=p;
                }
                else {
                    profit[1]=p;
                }
            }
        }

        i++;
    }
    p=max-min;
            if(p<profit[0]&&p<profit[1]) {

            }
            else if(p>profit[0]&&p<profit[1]) {
                profit[0]=p;
            }
            else if(p<profit[0]&&p>profit[1]) {
                profit[1]=p;
            }
            else {
                if(profit[0]<profit[1]) {
                    profit[0]=p;
                }
                else {
                    profit[1]=p;
                }
            }

    return profit[0]+profit[1];








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
        int ans=maximumProfit(arr,n);
        cout<<ans<<endl;
    }
}