#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    vector<ll> suff(n+1,0);

    for(int i = n-1; i>=0; i--){
        suff[i] = suff[i+1] + v[i];
    } 

    ll ans = suff[0];

    for(int i = 1; i<n; i++){
        if(suff[i] > 0){
            ans += suff[i];
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