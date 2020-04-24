#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(string s,string out,unordered_map<string,int> m,int l,int start) {
    
    if(start==l) {
        cout<<"("<<out<<")";
        return;
    }
    for(int i=start;i<l;i++) {
        string str=s.substr(start,i-start+1);
        if(m.find(str)!=m.end()) {
            
            out+=str+" ";
            solve(s,out,m,l,i+1);
            
        }
        
    }
    return ;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        unordered_map<string,int> m;
        while(n--) {
            string str;
            cin>>str;
            m[str]++;
        }
        string s;
        cin>>s;
        solve(s,"",m,s.length(),0);
        cout<<endl;
    }
}



