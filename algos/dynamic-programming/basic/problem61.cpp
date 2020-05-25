#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n,vector<int> out) {
    int k = 0;
    while (n % 2 == 0)
    {
        if(k==0) {
            out.push_back(2);
        }
        n = n / 2;
    }

    int root = sqrt(n);
    for (int i = 3; i <= root;i++) {
        k = 0;
        while (n % i == 0)
        {
            if(k==0) {
                out.push_back(i);
            }
            n = n / i;
        }
    }

    if(n>2) {
        out.push_back(n);
    }
    return out;
}

bool isPrime(int n) {
    int root = sqrt(n);

    for (int i = 2; i <= root;i++) {
        while(n%i==0) {
            return false;
        }
    }
    return true;
}

int solve(int *arr,int n,int index) {

    if(index==1) {
        return arr[0];
    }

    if(isPrime(index)) {
        return arr[index - 1] + solve(arr, n, 1);
    }
    vector<int> out;
    vector<int> pf = primeFactors(index, out);

    int maximum = INT_MIN;
    for (int i = 0; i < pf.size();i++) {
        maximum = max(maximum, arr[index - 1] + solve(arr,n,index/pf[i]));
    }
    return maximum;
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

        int *temp = new int[n];

        for(int i=0;i<n;i++) {
            temp[i]=solve(arr,n,i+1);
        }

        cout<<endl;

        for(int i=0;i<n;i++) {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    }
}