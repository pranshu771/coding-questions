#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int start,int end,int turn) {
    if(start==end) {
        return turn * arr[start];
    }

    return max(arr[start] * (turn) + solve(arr, start + 1, end,turn+1), arr[end] * (turn) + solve(arr, start, end - 1,turn+1));
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

        int ans = solve(arr, 0,n-1,1);
        cout << ans << endl;
    }
}