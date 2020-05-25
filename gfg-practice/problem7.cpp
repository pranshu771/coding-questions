using namespace std; 
#include<bits/stdc++.h>

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        stack<string> s;
        for(int i=0;i<n;i++) {
            s.push("0");
        }
        while(n!=0) {
            if(n>9) {
                s.push("9");
                n = n - 9;
            }
            else {
                char a = n + 48;
                string b = "";
                b += a;
                s.push(b);
                n = 0;
            }
        }

        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }
}