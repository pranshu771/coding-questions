#include<iostream>
using namespace std;
#include<bits/stdc++.h>



void solve(vector<int> v,int n,int i,int k,vector<int> out,vector<vector<int>> &output) {
    if(k<0) {
        return ;
    }
    if(k==0) {
        output.push_back(out);
        return ;
    }

    
    
    while(i<n&&k-v[i]>=0) {
        out.push_back(v[i]);
        solve(v,n,i,k-v[i],out,output);
        out.pop_back();
        i++;
        
    }
    return ;

    
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        int k;
        cin>>k;

        sort(v.begin(),v.end());
        vector<int>::iterator ip;
        ip=unique(v.begin(),v.begin()+n);
        v.resize(distance(v.begin(),ip));

        vector<int> out;
        vector<vector<int>> output;
        
        solve(v,v.size(),0,k,out,output);
        
        int size=output.size();
        if(size==0) {
            cout<<"Empty";
        }
        else {
            for(int i=0;i<size;i++) {
                vector<int> v=output[i];
                int l=v.size();
                if(l!=0) {
                    cout<<"(";
                    for(int i=0;i<l;i++) {
                        if(i==l-1) {
                            cout<<v[i];
                        }
                        else {
                            cout<<v[i]<<" ";
                        }
                    }
                    cout<<")";
                }
            }
        }



        cout<<endl;
        
    }
}