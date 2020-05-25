using namespace std; 
#include<bits/stdc++.h>

int solve(int *arr,int n) {
    int maximum = INT_MIN;
    int curmax = 0;
    bool temp = false;

    for (int i = 0; i < n;i++) {
        curmax += arr[i];
        if(curmax<0&&!temp) {
            curmax -= arr[i];
            temp = true;
        }
        if(curmax<0&&temp) {
            curmax = 0;
        }

        if(curmax>maximum) {
            maximum = curmax;
        }
    }
    return maximum;
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