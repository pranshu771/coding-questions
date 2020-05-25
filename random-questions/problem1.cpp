#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n) {
    int left = 0;
    int right = 0;
    int count = 0;

    for (int i = 1; i < n-1;i++) {
        left = 0;
        right = 0;
        for (int j = 0; j < i; j++)
        {
            if(arr[j]<arr[i]) {
                left++;
            }
        }
        for (int j = i + 1; j < n;j++) {
            if(arr[j]>arr[i]) {
                right++;
            }
        }

        count += (left * right);

    }
    return count;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int *arr=new int[n];
        for (int i = 0; i < n;i++) {
            cin >> arr[i];
        }

        int ans = solve(arr, n);
        cout << ans << endl;
    }
}