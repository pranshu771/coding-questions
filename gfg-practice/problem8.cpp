using namespace std; 
#include<bits/stdc++.h>

struct meeting{
    int start;
    int end;
    int pos;
};
bool compare(meeting a,meeting b) {
    return a.end < b.end;
}

void solve(vector<meeting> v) {
    int size = v.size();
    vector<int> vect;
    vect.push_back(v[0].pos);
    int endTime = v[0].end;

    for (int i = 1; i < size;i++) {
        if(v[i].start>endTime) {
            vect.push_back(v[i].pos);
            endTime = v[i].end;
        }
    }
    size = vect.size();
    for (int i = 0; i < size; i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int *S = new int[n];
        int *F = new int[n];

        for (int i = 0; i < n;i++) {
            cin >> S[i];
        }
        for (int i = 0; i < n;i++) {
            cin >> F[i];
        }

        vector<meeting> v;
        for (int i = 0; i < n;i++) {
            v.push_back({S[i], F[i], i+1});
        }
        sort(v.begin(), v.end(), compare);

        

        solve(v);
    }
}