#include<bits/stdc++.h>
using namespace std;

int largestSquareSubMatrix(int **arr,int n,int m) {

    int maximum=INT_MIN;
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(arr[i][j]==0) {
                
            }
            else {
                arr[i][j]=min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1]))+1;
                if(maximum<arr[i][j]) {
                    maximum=arr[i][j];
                }
            }
        }
    }
    return maximum;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,m;
        cin>>n>>m;

        int **arr=new int*[n];
        for(int i=0;i<n;i++) {
            arr[i]=new int[m];
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
            }
        }
        int ans=largestSquareSubMatrix(arr,n,m);
        cout<<ans<<endl;
    }
}