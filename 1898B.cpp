#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin>>n;
    vll v(n);

    for(int i = 0; i<n; i++) cin>>v[i];

    ll prev = INT_MAX;
    ll ans = 0;

    for(int i = n-1; i>=0; i--){
        if(v[i] <= prev){
            prev = v[i];
        }else{
            ll x = (v[i] + prev - 1)/prev;

            ans += x - 1;
            prev = v[i]/x;
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