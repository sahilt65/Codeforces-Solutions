#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n, x, y;
    cin>>n>>x>>y;
    vector<ll> v(n);

    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    map<ll,map<ll,ll> > mp;
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=mp[(x-v[i]%x)%x][v[i]%y];
        mp[v[i]%x][v[i]%y]++;
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}