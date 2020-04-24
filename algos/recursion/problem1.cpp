//generate all subsets 

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void generateSubsets(int *arr,int n,int start,vector<int> &subsets,vector<vector<int>> &res) {
    res.push_back(subsets);

    for(int i=start;i<n;i++) {
        subsets.push_back(arr[i]);
        generateSubsets(arr,n,i+1,subsets,res);
        subsets.pop_back();
    }
    return ;
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
        vector<int> subsets;
        vector<vector<int>> res;
        generateSubsets(arr,n,0,subsets,res);

        int size=res.size();
        for(int i=0;i<size;i++) {
            vector<int> v=res[i];
            int l=v.size();
            for(int i=0;i<l;i++) {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
}