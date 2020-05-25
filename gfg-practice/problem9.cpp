using namespace std; 
#include<bits/stdc++.h>

int minSpent(int *arr,int n,int k) {
    vector<int> v;
    for (int i = 0; i < n;i++) {
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    int money = 0;
    while (!v.empty())
    {
        money += v[0];
        
        v.erase(v.begin());

        if(v.size()>k) {
            v.erase(v.end() - k, v.end());
        }
        else {
            v.clear();
        }
    }
    return money;
}

int maxSpent(int *arr,int n,int k) {
    vector<int> v;
    for (int i = 0; i < n;i++) {
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    int money = 0;


    while (!v.empty())
    {
        
        money += v[v.size()-1];
        v.erase(v.end()-1);
        if(v.size()>k) {
            v.erase(v.begin(), v.begin() + k);
        }
        else {
            v.clear();
        }
    }
    return money;
}


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;

        int *arr = new int[n];
        for (int i = 0; i < n;i++) {
            cin >> arr[i];
        }

        int min = minSpent(arr, n,k);
        
        int max = maxSpent(arr, n,k);

        cout << min << " " << max << endl;
    }
}