//The function should return the modified array as specified in the problem statement 

vector<int> threeWayPartition(vector<int> arr, int l, int h) {
    vector<int> low;
    vector<int> range;
    vector<int> high;

    int n=arr.size();
    for(int i=0;i<n;i++) {
        if(arr[i]<l) {
            low.push_back(arr[i]);
        }
        else if(arr[i]>=l&&arr[i]<=h) {
            range.push_back(arr[i]);
        }
        else {
            high.push_back(arr[i]);
        }
    }

    int k=0;
    while(k<n) {
        for(int i=0;i<low.size();i++) {
            arr[k++]=low[i];
        }
        for(int i=0;i<range.size();i++) {
            arr[k++]=range[i];
        }
        for(int i=0;i<high.size();i++) {
            arr[k++]=high[i];
        }
    }
    return arr; 
}