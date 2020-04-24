#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool isSafe(int mat[][10],int visited[][10],int x,int y) {
    

if(mat[x][y]==0||visited[x][y]) {
    return false;
}
return true;

    
}

bool isValid(int x,int y) {
    if(x>=0&&y>=0&&x<12&&y<10) {
        return true;
    }
    return false;
}

void solve(int mat[][10],int visited[][10],int x,int y,int len,int &minLen) {

    //cout<<x<<" "<<y<<" "<<endl;

    if(x==11) {
        return ;
    }
    
    if(y==9) {
        minLen=min(len,minLen);
        
        return ;
    }

    if(len>minLen) {
        return ;
    }

    visited[x][y]=1;

    if(isValid(x+1,y)&&isSafe(mat,visited,x+1,y)) {
        solve(mat,visited,x+1,y,len+1,minLen);
    }
    if(isValid(x,y-1)&&isSafe(mat,visited,x,y-1)) {
        solve(mat,visited,x,y-1,len+1,minLen);
    }
    if(isValid(x,y+1)&&isSafe(mat,visited,x,y+1)) {
        solve(mat,visited,x,y+1,len+1,minLen);
    }
    if(isValid(x-1,y)&&isSafe(mat,visited,x-1,y)) {
        solve(mat,visited,x-1,y,len+1,minLen);
    }
    visited[x][y]=0;

    
    return ;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int mat[12][10];
        for(int i=0;i<12;i++) {
            for(int j=0;j<10;j++) {
                cin>>mat[i][j];
            }
        }

        //markunsafe

        for(int i=0;i<12;i++) {
            for(int j=0;j<10;j++) {
                if(mat[i][j]==0) {
                    if(isValid(i+1,j)) {
                        mat[i+1][j]=-1;
                    }
                    if(isValid(i-1,j)) {
                        mat[i-1][j]=-1;
                    }
                    if(isValid(i,j+1)) {
                        mat[i][j+1]=-1;
                    }
                    if(isValid(i,j-1)) {
                        mat[i][j-1]=-1;
                    }
                }
            }
        }

        for(int i=0;i<12;i++) {
            for(int j=0;j<10;j++) {
                if(mat[i][j]==-1) {
                    mat[i][j]=0;
                }
            }
        }
        int minLen=INT_MAX;
        cout<<endl;

        for(int i=0;i<12;i++) {
            for(int j=0;j<10;j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        int visited[12][10];
        
        for(int i=0;i<12;i++) {
            if(mat[i][0]==1) {
                memset(visited,0,sizeof visited);
                solve(mat,visited,i,0,0,minLen);

                if(minLen==12) {
                    break;
                }
            }
        }
        cout<<minLen<<endl;
    }
}