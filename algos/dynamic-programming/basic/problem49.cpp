#include<bits/stdc++.h>
using namespace std;

//takes no extra space

int maximumPathSum(int **arr,int n) {

    for(int i=n-2;i>=0;i--) {
        for(int j=0;j<=i;j++) {
            if(arr[i+1][j]>arr[i+1][j+1]) {
                arr[i][j]+=arr[i+1][j];
            }
            else {
                arr[i][j]+=arr[i+1][j+1];
            }
        }
    }
    return arr[0][0];
}



// int maximumPathSum(int **arr,int n) {
    
//     int dp[n][2]={0};
//     memset(dp,0,sizeof(dp));
//     dp[0][0]=arr[0][0];
//     dp[0][1]=0;

//     int down,right,index;
//     for(int i=1;i<n;i++) {
//         index=dp[i-1][1];
        
//         // left=(index>0)?arr[i][index-1]:0;
//         down=arr[i][index];
//         right=(index<n-1)?arr[i][index+1]:0;

        
//         if(down==max(down,right)) {
//             dp[i][0]=dp[i-1][0]+down;
//             dp[i][1]=index;
//         }
//         else {
//             dp[i][0]=dp[i-1][0]+right;
//             dp[i][1]=index+1;
//         }
        
//     }
//     return dp[n-1][0];
// }

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