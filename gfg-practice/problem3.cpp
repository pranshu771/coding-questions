    using namespace std; 
    #include<bits/stdc++.h>

long long int solve(int n) {
    int a = 1;
    int b = 1;
    int c = 2;

    int sum = 0;

    while(c<=n) {
        if(c%2==0) {
            sum += c;
        }
        a = b;
        b=c;
        c = a + b;

    }
    cout << sum << endl;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=solve(n);
    }
}