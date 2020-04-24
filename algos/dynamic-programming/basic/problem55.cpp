#include<bits/stdc++.h>
using namespace std;

int maximumSegments(int n,int a,int b,int c) {
    if(n==0) {
        return 1;
    }
    else {
        return 0;
    }

    return 1 + max(maximumSegments(n-a,a,b,c),max(maximumSegments(n-b,a,b,c),maximumSegments(n-c,a,b,c)));
} 

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int ans=maximumSegments(n,a,b,c);
        cout<<ans<<endl;
    }
}