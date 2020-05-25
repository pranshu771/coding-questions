#include<bits/stdc++.h>
using namespace std;

int count(int x,int y) {
    if(x==0 || y==0) {
        return 1;
    }
    return count(x - 1, y) + count(x, y - 1);
}

int main() {
    int t;
    cin>>t;

    int x,y;
    cin>>x>>y;

    int ans = count(x, y);
    cout << ans << endl;
}