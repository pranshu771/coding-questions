#include<bits/stdc++.h>
using namespace std;

int maximumPathSum(int **arr,int n) {

    for(int i=n-2;i>=0;i--) {
        for(int j=0;j<=i;j++) {
            if(arr[i+1][j]<arr[i+1][j+1]) {
                arr[i][j]+=arr[i+1][j];
            }
            else {
                arr[i][j]+=arr[i+1][j+1];
            }
        }
    }
    return arr[0][0];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int **arr=new int*[n];
        for(int i=0;i<n;i++) {
            arr[i]=new int[n];
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>arr[i][j];
            }
        }

        int ans=maximumPathSum(arr,n);
        cout<<ans<<endl;
    }
}