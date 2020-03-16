#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void solve(int *arr,int n) {
    int count=0;

    for(int i=0;i<n;i++) {
        if(arr[i]!=0) {
            arr[count]=arr[i];
            count++;
        }

    }
    while(count<n) {
        arr[count]=0;
        count++;
    }
    int i=0;
    while(i<n) {
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
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
	    solve(arr,n);
	    
	}
}