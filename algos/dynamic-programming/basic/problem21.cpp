#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int a[][4],int t[][4],int e[],int x[]) {
    int up = e[0] + a[0][0]; 
    int down = e[1] + a[1][0]; 
           
    for (int i = 1; i < 4; i++) { 
        int temp=up;
        up = min(up + a[0][i], down + t[1][i] + a[0][i]);
        down = min(down + a[1][i], temp + t[0][i] + a[1][i]); 
        
    } 
    return min(up+x[0], down+x[1]); 


}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int a[][4]={{4, 5, 3, 2},  
                            {2, 10, 1, 4}}; 
        int t[][4]={{0, 7, 4, 5},  
                            {0, 9, 2, 8}};
        

        

        int e[]={10,12};
        int x[]={18,7};

        int ans=solve(a,t,e,x);
        cout<<ans<<endl;
    }
}