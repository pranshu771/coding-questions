#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n,int rhs) {
    if(n==1) {
        if(rhs%arr[0]==0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int num = 0;
    for (int i = 0; i <= rhs; i += arr[n - 1])
    {
        num += solve(arr, n - 1, rhs - i);
    }
    return num;
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

        int rhs;
        cin >> rhs;
        int ans = solve(arr, n, rhs);
        cout << ans << endl;
    }
}