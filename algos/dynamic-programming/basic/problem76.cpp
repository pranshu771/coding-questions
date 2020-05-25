#include<bits/stdc++.h>
using namespace std;

bool isValid(int i,int j,int n) {
    if(i>=0&&i<n&&j>=0&&j<n) {
        return true;
    }
    return false;
}

int solve(int **arr,int n) {
    int endlessPoints = 0;

    int row[n][n];
    int col[n][n];
    memset(row, true, sizeof(row));
    memset(col, true, sizeof(col));

    for (int i = 0; i < n;i++) {
        row[i][n - 1] = arr[i][n - 1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if(arr[i][j]==0) {
                row[i][j] = 0;
            }
            else if(row[i][j+1]==1) {
                row[i][j] = 1;
            }
            else {
                row[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < n;j++) {
        col[n - 1][j] = arr[n - 1][j];
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = n - 2; i >= 0; i--)
        {
            if(arr[i][j]==0) {
                col[i][j] = 0;
            }
            else if(col[i+1][j]==1) {
                col[i][j] = 1;
            }
            else {
                col[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            if(row[i][j]==1&&col[i][j]==1) {
                endlessPoints++;
            }
        }
    }
    return endlessPoints;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
        }

        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++) {
                cin >> arr[i][j];
            }
        }
        int ans = solve(arr,n);
        cout << ans << endl;
    }
}