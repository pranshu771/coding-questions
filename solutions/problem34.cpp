#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(int *a1,int *a2,int n1,int n2) {
    int start1,start2,end1,end2=0;
    while(start1<n1&&start2<n2) {
        while(arr2[start2]<=arr1[start1]) {
            start2++;
        }
        end1=start1;
        end2=start2;    
    }
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n1,n2;
        cin>>n1>>n2;

        int *arr1=new int[n1];
        for(int i=0;i<n1;i++) {
            cin>>arr1[i];
        }

        int *arr2=new int[n2];
        for(int i=0;i<n2;i++) {
            cin>>arr2[i];
        }

        solve(arr1,arr2,n1,n2);
    }
}