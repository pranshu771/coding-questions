#include<iostream>
using namespace std;
#include<bits/stdc++.h>



void solve(vector<pair<int,int>> arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int i=0;
    while(i<n-1) {
        if(arr[i+1].first<=arr[i].second) {
            int l=min(arr[i].first,arr[i+1].first);
            int r=max(arr[i].second,arr[i+1].second);
            arr[i]=make_pair(-1,-1);
            arr[i+1]=make_pair(l,r);
            


        }
        i++;
    }
    vector<pair<int,int>> output;
    for(int i=0;i<n;i++) {
        if(arr[i].first==-1&&arr[i].second==-1) {

        }
        else {
            output.push_back(arr[i]);
        }
    }
    

    for(int i=0;i<output.size();i++) {
        cout<<output[i].first<<" "<<output[i].second<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            v.push_back(pair<int,int>(a,b));
        }
        solve(v);

    }
}