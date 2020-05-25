#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n,int k) {

    int start = 0;
    int end = n - 1;

    sort(arr, arr + n);
    int minRemovals = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        start = i;
        end = n - 1;
        
        while(start<=end) {
            if(arr[end]-arr[start]<=k) {
                break;
            }
            else {
                end--;
            }
        }
        if(start>end) {

        }
        else {
            minRemovals = min(minRemovals, start + (n - 1 - end));
        }
    }
    return minRemovals;
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
        int k;
        cin >> k;

        int ans = solve(arr, n, k);
        cout << ans << endl;
    }
}