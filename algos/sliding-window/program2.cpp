//solving with sliding window method
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool checkAnagrams(string s,int *arr) {
    int altArray[26];
    for(int i=0;i<26;i++) {
        altArray[i]=arr[i];
    }
    int index;
    for(int i=0;i<s.length();i++) {
        index=s[i]-97;
        altArray[index]--;
    }
    for(int i=0;i<26;i++) {
        if(altArray[i]>0) {
            return false;
        }
    }
    return true;
}

int solve(string s,string c) {
    int altArray[26];
    for(int i=0;i<26;i++) {
        altArray[i]=0;
    }
    int index;
    for(int i=0;i<c.length();i++) {
        index=c[i]-97;
        altArray[index]++;
    }
    
    int wordLength=c.length();
    int start=0;
    string str=s.substr(start,wordLength);
    
    while(!checkAnagrams(str,altArray)) {
        
        start++;
        str=s.substr(start,wordLength);
        if(!s[start]) {
            return 0;
        }
        
    }
    if(!str[start]&&!checkAnagrams(str,altArray)) {
        return 0;
    } 
    
    int end=start+wordLength;
    int score=0;
    int count=1;
    int freq[26];
    for(int i=0;i<26;i++) {
        freq[i]=0;
    }
    for(int i=0;i<str.length();i++) {
        freq[str[i]-97]++;
    }
    while(s[end]) {
        freq[s[start]-97]--;
        freq[s[end]-97]++;
        for(int i=0;i<26;i++) {
            if(freq[i]==altArray[i]) {
                if(i==25) {
                    count++;
                }

            }
            else {
                break;
            }
        }
        start++;
        end++;
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        string c;
        cin>>s>>c;
        int ans=solve(s,c);
        cout<<ans<<endl;
    }
}