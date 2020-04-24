#include<bits/stdc++.h>
using namespace std;

void PrintMaxLenChainPairs(vector<pair<int,int>> v,int n) {
    
    int dp[n]={0};
    dp[0]=1;
    sort(v.begin(),v.end());

    vector<pair<int,int>> out;
    for(int i=1;i<n;i++) {
        dp[i]=1;
        for(int j=0;j<i;j++) {
            if(v[i].first>v[j].second&&dp[i]<dp[j]+1) {
                
                dp[i]=dp[j]+1;
            }
        }
    }

    int maximum=INT_MIN;
    int index;
    for(int i=0;i<n;i++) {
        if(dp[i]>maximum) {
            maximum=dp[i];
            index=i;
        }
    }
    out.push_back(v[index]);
    maximum--;
    pair<int,int> p;
    
    
    while(index!=-1&&maximum) {
        p=out.back();
        if(dp[index]==maximum&&v[index].second<p.first) {
            out.push_back(v[index]);
            maximum--;
        }
        
        index--;

    }

    int size=out.size();
    for(int i=size-1;i>=0;i--) {
        cout<<out[i].first<<" "<<out[i].second<<" ";
    }
    cout<<endl;

    
    
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i].first;
            cin>>v[i].second;
        }

        PrintMaxLenChainPairs(v,n);
        

    }
}