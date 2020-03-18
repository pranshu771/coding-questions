    #include <iostream>
    using namespace std;
    #include<bits/stdc++.h>

    int solve(int *arr,int n,int l,int r) {
    
        int ans=0;
        int start=0;
        int end=0;
        int len=1;
        int maximum=INT_MIN;
        int count=0;

        while(end<n) {
            maximum=max(maximum,arr[end]);

            if(arr[end]<l) {
                count++;
            }

            if(maximum>=l&&maximum<=r) {
                end++;
                len++;
                
            }
            else {
                if(maximum<l) {
                    end++;
                    len++;
                }
                else {
                    ans+=len*(len-1)/2;
                    ans-=count*(count+1)/2;
                    start=end+1;
                    end++;
                    len=1;
                    maximum=INT_MIN;
                    count=0;

                }
            }
        }

        ans+=len*(len-1)/2;
        ans-=count*(count+1)/2;
        return ans;
        
    }

    int main() {
        int t;
        cin>>t;
        
        while(t--) {
            int n,l,r;
            cin>>n>>l>>r;

            int *arr=new int[n];
            for(int i=0;i<n;i++) {
                cin>>arr[i];
            }

            int ans=solve(arr,n,l,r);
            cout<<ans<<endl;
        }
    }