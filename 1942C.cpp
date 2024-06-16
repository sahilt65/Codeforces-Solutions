#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n, x, y;
    cin>>n>>x>>y;

    vector<ll> v(x);
    set<ll> s;
    ll ans = x-2;
    for(int i = 0; i<x; i++){
        cin>>v[i];
        v[i]--;
        s.insert(v[i]);
    }

    for(int i = 0; i<x; i++){
        ll next = (v[i] + 1)%n;
        ll afterNext = (v[i] + 2)%n;

        if(!s.count(next) && s.count(afterNext)){
            ans++;
        }
    }

    cout<<ans<<endl;

}


int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}