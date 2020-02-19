#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int **arr,int n) {
    int temp;
    for(int i=0;i<n/2;i++) {
        for(int j=i;j<n-i-1;j++) {
            temp=arr[i][j];
            arr[i][j]=arr[j][n-i-1];
            arr[j][n-i-1]=arr[n-i-1][n-1-j];
            arr[n-i-1][n-j-1]=arr[n-j-1][i];
            arr[n-j-1][i]=temp;
        }
        
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int **mat=new int*[n];
        for(int i=0;i<n;i++) {
            mat[i]=new int[n];
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>mat[i][j];
            }
        }
        solve(mat,n);
    }
}