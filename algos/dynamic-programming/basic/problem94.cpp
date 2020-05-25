#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n) {

    int minimumEndingHere = 0;
    int minimum = INT_MAX;

    for (int i = 0; i < n;i++) {
        
        if(minimumEndingHere>0) {
            minimumEndingHere = arr[i];
        }
        else {
            minimumEndingHere += arr[i];
        }

        if(minimumEndingHere<minimum) {
            minimum = minimumEndingHere;
        }
    }

    return minimum;
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

        int ans = solve(arr, n);
        cout << ans << endl;
    }
}