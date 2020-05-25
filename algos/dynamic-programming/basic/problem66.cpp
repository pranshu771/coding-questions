    #include<bits/stdc++.h>
    using namespace std;

    // int minJumps(int *arr,int n,int index,map<int,int> m) {

    //     if(arr[index]==0) {
    //         return INT_MAX;
    //     }

    //     if(arr[index]>=n-index-1) {
    //         return 1;
    //     }

        

    //     if(m.find(index)!=m.end()) {
    //         return m[index];
    //     }

    //     int res = INT_MAX;
    //     for (int i = 1; i <= arr[index];i++) {
    //         int subRes = minJumps(arr, n, index + i,m);
    //         res = min(res, subRes);
    //     }
    //     m[index] = res + 1;
    //     return m[index];
    // }

    int minJumps(int *arr,int n) {

        int dp[n];

        for (int i = 0; i < n;i++) {
            dp[i] = INT_MAX;
        }

        if(arr[0]==0) {
            return -1;
        }

        dp[0] = 1;
        for (int i = 0; i < n;i++) {
            for (int j = i + 1; j <= i + arr[i]&&j<n;j++) {
                if(arr[j]==0&&j!=n-1) {

                }
                else {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1]-1;
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
            map<int, int> mem;
            int ans = minJumps(arr, n);
            cout << ans << endl;
        }
    }