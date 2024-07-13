#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

bool check(vector<int> premutation, ll sum, vector<vector<ll>> &v){
    ll s = 0;
    int ind = 0;
    int l = 0;

    vector<pair<int, pair<int, int>>> ans;
    for(int i = 0; i<v[ind].size(); i++){
        s += v[premutation[ind]][i];

        if(s >= sum){
            ans.push_back({premutation[ind], {l, i}});
            ind++;
            s = 0;
            l = i + 1;
            if(ind == 3) break;
        }
    }

    if(ind == 3){
        sort(ans.begin(), ans.end());
        for(auto &i : ans){
            cout<<i.second.first + 1<< " "<<i.second.second + 1<<" ";
        }
        cout<<endl;
        return true;
    }else{
        return false;
    }
}
void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> v(3, vector<ll> (n));

    for(int i = 0; i<3; i++){
        for(int j = 0; j<n; j++) cin>>v[i][j];
    }

    ll sum = 0;
    for(int i = 0; i<n; i++) sum += v[0][i];
    if(sum%3 == 0) sum = sum/3;
    else sum = sum / 3 + 1;
    if(check({0, 1, 2}, sum, v)) return;
    if(check({0, 2, 1}, sum, v)) return;
    if(check({1, 0, 2}, sum, v)) return;
    if(check({1, 2, 0}, sum, v)) return;
    if(check({2, 1, 0}, sum, v)) return;
    if(check({2, 0, 1}, sum, v)) return;
    cout<<"-1"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}