#include<bits/stdc++.h>
using namespace std;

pair<int,int> kadane(int *arr,int n) {
    int maximumSum = INT_MIN;
    int maximumEndingHere = 0;
    int endIndex = -1;

    for (int i = 0; i < n;i++) {
        maximumEndingHere += arr[i];

        if(maximumSum<maximumEndingHere) {
            maximumSum = maximumEndingHere;
            endIndex = i;
        }

        if(maximumEndingHere<0) {
            maximumEndingHere = 0;
        }
        
        
    }
    pair<int, int> p = make_pair(maximumSum, endIndex);
    return p;
}

int arrSum(int *arr,int start,int end,int n) {
    int sum = 0;
    for (int i = start; i < start + n; i++)
    {
        sum += arr[i % (n)];

    }
    return sum;
}

pair<int,int> kadane2(int *arr,int start,int end,int sum,int n) {
    int endingIndex = -1;
    pair<int, int> p;
    for (int i = start + n - 1; i >= start; i--)
    {
        if(sum-arr[i%(n-1)]>0) {
            p = make_pair(sum - arr[i%(n-1)], i);
            return p;
        }

        sum -= arr[i % (n - 1)];
    }
    if(sum<0) {
        sum = 0;
    }
    p = make_pair(sum, end);
    return p;
}

int maximumSum(int *arr,int n,int k) {
    int dp[k];
    memset(dp, 0, sizeof(dp));

    pair<int, int> p = kadane(arr, n);
    dp[0] = p.first;
    int endIndex = p.second;

    int sum = arrSum(arr,endIndex+1,endIndex,n);
    //cout << " sum: " << sum << endl;

    int i = 1;
    pair<int, int> q;
    while (sum < 0 && i < k)
    {
        q = kadane2(arr, endIndex + 1, endIndex, sum, n);
        cout << "kadaneSum: " << q.first << endl;
        dp[i] = dp[i - 1] + q.first;
        endIndex = q.second;

        sum = arrSum(arr, endIndex + 1, endIndex, n);
        i++;
    }
    if(sum>0&&i<k) {
        dp[k - 1] = dp[i-1] + sum * (k - i);
    }

    return dp[k-1];
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
        int k;
        cin >> k;
        int ans = maximumSum(arr, n,k);
        cout << ans << endl;
    }
}