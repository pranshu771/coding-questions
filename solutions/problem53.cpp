#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class pairSum {
    public:
    int first;
    int second;
    int sum;
};

class quad {
    public:
    int first;
    int second;
    int third;
    int fourth;
};

int binarySearch(vector<pairSum> aux,int l,int r,int num) {
    if(r<l) {
        return -1;
    }

    int mid=(l+r)/2;
    if(aux[mid].sum==num) {
        return mid;
    }
    else if(num<aux[mid].sum) {
        return binarySearch(aux,l,mid-1,num);
    }
    else {
        return binarySearch(aux,mid+1,r,num);
    }

}

int mycompare(pairSum x,pairSum y) {
    return (x.sum<y.sum);
}

bool noCommon(pairSum a,pairSum b) {
    if(a.first==b.second||a.second==b.first||a.first==b.first||a.second==b.second) {
        return false;
    }
    return true;
}

vector<quad> solve(int *arr,int n,int num) {

int size=n*(n-1)/2;
vector<pairSum> aux;

int k=0;
for(int i=0;i<n-1;i++) {
    for(int j=i+1;j<n;j++) {
        pairSum p;
        p.first=arr[i];
        p.second=arr[j];
        p.sum=arr[i]+arr[j];
        aux.push_back(p);
        k++;
    }
}

vector<quad> out;
sort(aux.begin(),aux.end(),mycompare);
for(int i=0;i<size;i++) {
    if(aux[i].sum<=num) {
        int index=binarySearch(aux,i+1,aux.size()-1,num-aux[i].sum);
        if(index!=-1&&(noCommon(aux[i],aux[index]))) {
            

            quad q;
            q.first=aux[i].first;
            q.second=aux[i].second;
            q.third=aux[index].first;
            q.fourth=aux[index].second;
            out.push_back(q);
            

            
        }
        
    }
}
return out;

}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        int *arr=new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        vector<quad> ans=solve(arr,n,k);
        if(ans.size()) {
            for(int i=0;i<ans.size();i++) {
                cout<<ans[i].first<<" "<<ans[i].second<<" "<<ans[i].third<<" "<<ans[i].fourth<<" $ ";
            }
        }
        else {
            cout<<-1;
        }
        
        cout<<endl;
    }
}