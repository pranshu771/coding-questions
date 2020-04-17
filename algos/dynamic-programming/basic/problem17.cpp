#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maximumTime(int A,int B,pair<int,int> X,pair<int,int> Y,pair<int,int> Z,int last,map<pair<int,int>,int> mem) {

    if(A<=0 || B<=0) {
        return 0;
    }

    pair<int,int> cur=make_pair(A,B);
    if(mem.find(cur)!=mem.end()) {
        return mem[cur];
    }

    int temp;

    switch(last) {
        case 1:
            temp = 1 + max(maximumTime(A+Y.first,B+Y.second,X,Y,Z,2,mem),
                            maximumTime(A+Z.first,B+Z.second,X,Y,Z,3,mem));
            break;

        case 2:
            temp = 1 + max(maximumTime(A+X.first,B+X.second,X,Y,Z,1,mem),
                            maximumTime(A+Z.first,B+Z.second,X,Y,Z,3,mem));
            break;

        case 3:
            temp = 1 + max(maximumTime(A+X.first,B+X.second,X,Y,Z,1,mem),
                            maximumTime(A+Y.first,B+Y.second,X,Y,Z,2,mem));
            break;
    }
    mem[cur]=temp;
    return temp;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int A,B;
        cin>>A>>B;

        pair<int,int> X,Y,Z;
        cin>>X.first;
        cin>>X.second;
        cin>>Y.first;
        cin>>Y.second;
        cin>>Z.first;
        cin>>Z.second;

        
        map<pair<int,int>,int> mem;

        int ans=max(maximumTime(A+X.first,B+X.first,X,Y,Z,1,mem),
                    max(maximumTime(A+Y.first,B+Y.first,X,Y,Z,2,mem),
                        maximumTime(A+Z.first,B+Z.first,X,Y,Z,3,mem)));

        cout<<ans<<endl;


    }
}