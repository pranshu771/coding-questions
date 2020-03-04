#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int findPivot(int *arr,int l,int h) {
    if(l>=h) {
        return -1;
    }
    int mid=(l+h)/2;
    if(arr[mid]<arr[mid+1]) {
        
        if(findPivot(arr,l,mid)==-1&&findPivot(arr,mid+1,h)==-1) {
            return -1;
        }
        else if(findPivot(arr,l,mid)!=-1) {
            return findPivot(arr,l,mid);
        }
        else if(findPivot(arr,mid+1,h)!=-1) {
            return findPivot(arr,mid+1,h);
        }
    }
    else {
        return mid;
    }
}



int binarySearch(int *arr, int l, int h, int k) 
{ 
     
    if(l>h) {
        return -1;
    }
    int mid=(l+h)/2;
    if(arr[mid]==k) {
        return mid;
    }
    if (arr[mid] > k) {
        return binarySearch(arr, l, mid - 1, k); 
    }
            
    else {
        return binarySearch(arr, mid + 1, h, k); 
    }
} 

int findIndex(int *arr,int n,int k) {
    int pivotIndex=findPivot(arr,0,n-1);
    int leftIndex=binarySearch(arr,0,pivotIndex,k);
    int rightIndex=binarySearch(arr,pivotIndex+1,n-1,k);
    if(leftIndex==-1&&rightIndex==-1) {
        return -1;
    }
    else if(leftIndex!=-1) {
        return leftIndex;
    }
    else {
        return rightIndex;
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
        int k;
        cin>>k;
        int index=findIndex(arr,n,k);
        cout<<index<<endl;
    }

}