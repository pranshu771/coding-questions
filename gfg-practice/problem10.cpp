using namespace std; 
#include<bits/stdc++.h>

int main() {
    vector<int> v;

    for(int i=0;i<10;i++) {
        v.push_back(i);
    }

    
    v.erase(v.begin());

    for (int i = 0; i < v.size();i++) {
        cout << v[i] << " ";
    }
    
}