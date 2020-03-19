#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool myCompare(string x,string y) {
    string xy=x.append(y);
    string yx=y.append(x);
    if(xy.compare(yx)>0) {
        return true;
    }
    else {
        return false;
    }
}

vector<string> solve(vector<string> arr,int n) {
    sort(arr.begin(),arr.end(),myCompare);
    return arr;
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
        vector<string> a;
        for(int i=0;i<n;i++) {
            string s=to_string(arr[i]);
            a.push_back(s);
        }

        vector<string> ans=solve(a,n);

        for(int i=0;i<n;i++) {
            cout<<ans[i];
        }
        cout<<endl;

        
    }
}