#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
	
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    int *arr=new int[n];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    
	    sort(arr,arr+n);
	    int count=0;
	    for(int i=0;i<n;i++) {
	        if(k>arr[i]) {
	            k=k-arr[i];
	        }
	        else {
                cout << count << endl;
                return 0;
            }
            count++;
        }
        cout<<count<<endl;
	    
	}
}