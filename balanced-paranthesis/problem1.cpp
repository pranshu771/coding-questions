#include <iostream>
using namespace std;
#include<bits/stdc++.h>

bool checkbalancedParanthesis(char *str,int n) {
    stack<char> st;

    for (int i = 0; str[i];i++) {
        if(str[i]=='(') {
            st.push('(');
        }
        else if(str[i]=='{') {
            st.push('{');
        }
        else if(str[i]=='[') {
            st.push('[');
        }
        else if(str[i]==')') {
            if(st.top()=='(') {
                st.pop();
            }
            else {
                return false;
            }
        }
        else if(str[i]=='}') {
            if(st.top()=='{') {
                st.pop();
            }
            else {
                return false;
            }
        }
        else if(str[i]==']') {
            if(st.top()=='[') {
                st.pop();
            }
            else {
                return false;
            }
        }
        
    }

    return st.size() == 0;
}

int main() {
    int t;
    cin >> t;

    

    while(t--) {
        int n;
        cin >> n;
        char *str = new char[n];
        for (int i = 0; i < n;i++) {
            cin >> str[i];
        }
        bool ans=checkbalancedParanthesis(str, n);
        cout << ans << endl;
    }
}