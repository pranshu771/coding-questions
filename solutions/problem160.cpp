#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int row[]={0,1,-1,0};
int col[]={1,0,0,-1};

bool isValid(int i,int j,int m,int n) {
    if(i>=0&&i<m&&j>=0&&j<n) {
        return true;
    }
    return false;
}

bool isSafe(int **arr,int m,int n,int i,int j,bool **visited) {
    if(arr[i][j]==1&&!visited[i][j]) {
        return true;
    }
    return false;
}

void maximumPath(int **arr,bool **visited,int m,int n,int x,int y,int len,int &maxLen) {
    //cout<<x<<" "<<y<<" ";
    
    if(x==m-1&&y==n-1) {
        maxLen=max(len+1,maxLen);
        return ;
    }

    visited[x][y]=true;
    
    for(int k=0;k<4;k++) {
        if(isValid(x+row[k],y+col[k],m,n)&&isSafe(arr,m,n,x+row[k],y+col[k],visited)) {
            maximumPath(arr,visited,m,n,x+row[k],y+col[k],len+1,maxLen);
        }
    }
    visited[x][y]=false;

    return ;



    
}

void solve(int **arr,int m,int n) {
    int maxLen=0;
    bool **visited=new bool*[m];
    for(int i=0;i<m;i++) {
        visited[i]=new bool[n];
    }
    //memset(visited,false,sizeof visited);

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            visited[i][j]=false;
        }
    }

    // for(int i=0;i<m;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    maximumPath(arr,visited,m,n,0,0,0,maxLen);
    cout<<maxLen<<endl;
}


int main() {
    int t;
    cin>>t;

    while(t--) {
        int m,n;
        cin>>m>>n;

        int **arr=new int*[m];
        for(int i=0;i<m;i++) {
            arr[i]=new int[n];
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin>>arr[i][j];
            }
        }

        solve(arr,m,n);

    }
}