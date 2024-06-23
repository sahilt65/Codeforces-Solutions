#include<bits/stdc++.h>
using namespace std;

#define ll long long

 
void dfs(ll s,ll p,vector<ll> adj[],vector<ll> &leaf){
    bool any=false;
    
    for(auto e : adj[s]){
        if(e==p) continue;
        any = true;
        dfs(e, s, adj, leaf);
        leaf[s] += leaf[e];
    }
    
    if(!any) leaf[s]++;
}

void solve(){
    int n;
    cin>>n;

    vector<ll> v[n+1];

    for(int i = 0; i<n-1; i++){
        ll a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin>>q;

    vector<ll> leaf(n+1, 0);
    dfs(1, -1, v, leaf);

    while(q--){
        ll a,b;
        cin>>a>>b;

        ll ans = leaf[a] * leaf[b];
        cout<<ans<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}