#include<bits/stdc++.h>
using namespace std;



int solve(int *arr,int n) {

    map<int, int> hash;
    for (int i = 0; i < n;i++) {
        if(hash.find(arr[i])!=hash.end()) {
            hash[arr[i]]++;
        }
        else {
            hash[arr[i]] = 1;
        }
    }

    int maximum = *max_element(arr, arr + n);
    for (int i = 2; i <= maximum;i++) {
        hash[i] = max(hash[i - 1], hash[i - 2] + hash[i] * i);
    }
    return hash[maximum];

    
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n;i++) {
            cin >> arr[i];
        }
        int ans=solve(arr,n);
        cout<<ans<<endl;
    }
}