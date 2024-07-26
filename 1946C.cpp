#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
bool ok(int treeSz, int k, vector<int> adj[]) {
    int cuts = 0;
 
    function<int(int, int)>dfs = [&](int node, int parent) {
 
        int sz = 1;
 
        for(auto &i : adj[node]) {
            if(i != parent) {
                sz += dfs(i, node);
            }
        }
 
        if(sz >= treeSz) sz = 0, cuts++;
 
        return sz;
 
    }; 
    dfs(1, 1);
 
    return cuts > k;
}
void solve() {
    int n, k; cin >> n >> k;
    vector<int>adj[n + 1];
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    int left = 0, right = n, answer = 0;
 
 
    while(left <= right) {
        int mid = (left + right) / 2;
        if(ok(mid, k, adj)) answer = mid, left = mid + 1;
        else right = mid - 1;
    }
 
    cout << answer << "\n";
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}