#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mex(vector<ll> &arr){
    sort(arr.begin(), arr.end());
    int mex = 0;
    for (int idx = 0; idx < arr.size(); idx++){
        if (arr[idx] == mex){
            mex += 1;
        }
    }
    return mex;
}
ll beauty(vector<vector<ll> > ans){
    vector<ll> arr;
    ll n= ans.size();
    ll m = ans[0].size();

    for(int i = 0; i<m; i++){
        vector<ll> col;
        for(int j = 0; j<n; j++){
            col.push_back(ans[j][i]);
        }

        arr.push_back(mex(col));
    }

    return mex(arr);
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<ll> > ans(n, vector<ll> (m, 0));

    ll sr = 0;
    for(int i =0;i<n; i++){
        if(sr < m-1) sr++;
        ll sc = sr;
        for(int j = 0; j<m; j++){
            ans[i][sc]= j;
            sc = (sc + 1)%m;
        }
    }
    cout<<beauty(ans)<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}