#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maxLengthBitonicArray(int *arr,int n) {
    if(n==1) {
        return 1;
    }
    int start=0;
    int end=start+1;
    bool up=false;
    bool down=false;
    
    int maxlen=-100000;
    int len=0;
    int count=0;
    while(end<n) {
        count=0;
        while(arr[end-1]<=arr[end]&&end<n) {
            end++;
            up=true;
            if(arr[end-1]==arr[end]) {
                count++;
            }
        }
        while(arr[end-1]>=arr[end]&&end<n) {
            end++;
            down=true;
            if(arr[end-1]==arr[end]) {
                count++;
            }
        }
        len=end-start-count;
        if(len>maxlen) {
            maxlen=len;
        }
        if(up&&down) {
            start=end-1;

        }
        else if(!up&&down) {
            start=end-1;
        }
        else {

        }
        up=false;
        down=false;

    }
    return maxlen;
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
        int ans=maxLengthBitonicArray(arr,n);
        cout<<ans<<endl;
    }
}