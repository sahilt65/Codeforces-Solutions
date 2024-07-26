#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
void solve() {
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);

    for(ll i = 0; i<n; i++) cin>>v[i];

    if(k >= 3){
        cout<<"0\n";
        return;
    }

    sort(v.begin(), v.end());
    ll d = v[0];
    for (ll i = 0; i < n - 1; i++) d = min(d, v[i + 1] - v[i]);
    if (k == 1) {
        cout << d << endl;
        return;
    }
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < i; j++) {
            ll x = v[i] - v[j];
            ll p = lower_bound(begin(v), end(v), x) - begin(v);
            if (p < n) d = min(d, v[p] - x);
            if (p > 0) d = min(d, x - v[p - 1]);
        }
    }
    cout << d << endl;

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}