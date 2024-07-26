#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin>>n;

    vector<ll> v(n);

    for(int i = 0; i<n; i++) cin>>v[i];

    if(n==1){
        ll ans = max(0ll, v[0]);
        cout<<ans<<endl;
        return;
    }

    if(v[0] >=0){
        ll ans = 0;
        for(auto i : v) ans += max(0ll, i);
        cout<<ans<<endl;
        return;
    }

    if(v[0] + v[1] >= 0){
        ll ans = v[0];
        for(auto i : v) ans += max(0ll, i);
        cout<<ans<<endl;
        return;
    }
    ll ans = 0;
    for(int i = 2; i<n; i++){
        ans += max(0ll, v[i]);
    }

    cout<<ans<<endl;
    return;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}