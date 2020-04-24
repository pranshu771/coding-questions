#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int summation(vector<int> v) {
    int n=v.size();
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=v[i];
    }
    return sum;
}

int average(int a,int b) {
    if(b!=0) {
        return a/b;
    }
}

void print(vector<int> v) {
    int n=v.size();
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void solve(int *arr,int n,vector<int> v1,vector<int> v2,int l1,int l2,int sum1,int sum2,int start) {
    if((l1!=0&&l2!=0)&&(average(sum1,l1)==average(sum2,l2))) {
        v1.clear();

        for(int i=0;i<n;i++) {
            if(arr[i]!=v2[i]) {
                v1.push_back(arr[i]);
            }
        }
        //print(v1);
        print(v2);
        return ;
    }

    for(int i=start;i<n;i++) {
        v2.push_back(arr[i]);
        sum2+=v1[i];
        sum1-=v1[i];
        solve(arr,n,v1,v2,l1-1,l2+1,sum1,sum2,i+1);
        v2.pop_back();
        sum2-=v1[i];
        sum1+=v1[i];

    }


    for(int i=start;i<n;i++) {

    }
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        vector<int> v1(n);
        vector<int> v2;
        for(int i=0;i<n;i++) {
            v1[i]=arr[i];
        }

        int sum=summation(v1);
        solve(arr,n,v1,v2,n,0,sum,0,0);
        cout<<endl;
    }
}