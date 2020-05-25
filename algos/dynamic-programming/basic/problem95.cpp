#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
    for (auto it = v.begin(); it != v.end();it++) {
        cout << *it << " ";
    }
}

bool checkVector(vector<int> v) {

    print(v);
    cout << endl
         << endl;
    
    int l = v.size();

    if (l == 1)
    {
        return false;
    }
    for (int i = 1; i < l;i++) {
        if(v[i]>v[i-1]) {
            return true;
        }
    }
    return false;
}

int solve(vector<int> input,int n) {
    if(input.size()==1) {
        return 1;
    }

    while(checkVector(input)) {
        int prev=INT_MIN;
        int l = input.size();

        for (auto it = input.begin(); it != input.end();it++) {
            if(*it>prev) {
                prev = *it;
                input.erase(it);
                it--;
            }
        }
    }

    return input.size();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n;i++) {
            cin >> input[i];
        }

        cout << endl
             << endl
             << endl;

        int ans = solve(input, n);
        ans = (ans == 0) ? -1 : ans;
        //cout << ans << endl;
    }
}