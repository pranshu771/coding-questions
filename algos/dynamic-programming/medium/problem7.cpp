#include<bits/stdc++.h>
using namespace std;

bool checkDivisibility(int k,int *prime,int size) {
    for (int i = 0; i < size;i++) {
        if(prime[i]<k) {
            if(k%prime[i]==0) {
                return true;
            }
        }
        else if(k==prime[i]) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

int solve(int n,int *prime,int size) {

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;

    int i = 2;
    int temp;
    while (i <= n)
    {
        
        

        int k = dp[i - 1] + 1;
        while(true) {
            if(checkDivisibility(k,prime,size)) {
                dp[i] = k;
                break;
            }
            k++;
        }
        
        i++;
    }

    return dp[n];
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,size;
        cin >> n >> size;
        int *primeList = new int[size];
        for (int i = 0; i < size;i++) {
            cin >> primeList[i];
        }

        int ans = solve(n, primeList, size);
        cout << ans << endl;
    }
}