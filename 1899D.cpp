#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
    map<ll, ll> mp;
    
    for(int i = 0; i<n; i++){
        cin>>v[i];
        mp[v[i]]++;
    }

    ll ans = 0;

    for(auto i : mp){
        ll x = i.second;
        ll a = x * (x-1)/2;
        ans += a;
    }
    ll x = mp[1]* mp[2];

    ans +=  x;

    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}