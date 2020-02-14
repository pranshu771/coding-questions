//solution to problem2 with sliding window method

#include<iostream>
using namespace std;

void solve(int *arr,int n,int k) {
    int sum=0;
    int start=1;
    int end=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
        end++;
        if(sum==k) {
            cout<<start<<" "<<end;
            return ;
        }
        else if(sum>k) {
            while(sum>=k&&start<=end) {
                sum=sum-arr[start-1];
                start++;
                if(sum==k) {
                    cout<<start<<" "<<end;
                    return ;
                }
            }
        }
        else {

        }
    }
    cout<<"-1";
    return ;
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
        solve(arr,n,k);
        cout<<endl;
    }
}