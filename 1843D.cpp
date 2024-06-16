#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;

    vector<vector<ll>> v(n+1);

    for(int i = 0; i<n-1; i++){
        ll a, b;

        if(a<b) v[a].push_back(b);
        else v[b].push_back(a);
    }

    int q;
    cin>>q;

    while(q--){
        ll a, b;
        cin>>a>>b;

        set<ll> s;

        for(auto i : v[a]){
            
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}