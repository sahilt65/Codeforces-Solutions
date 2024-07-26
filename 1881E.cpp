#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    ll n;
    cin>>n;
    vector<ll> v(n);

    for(int i = 0; i<n; i++) cin>>v[i];

    vector<ll> dp(n+1);
    dp[n-1] = 1;
    for(ll i = n-2; i>=0; i--){
        ll rightEle = n - i - 1;
        ll take =INT_MAX;
        if(v[i] + i  < n)  take = dp[i + v[i] + 1];
        ll notTake = 1 + dp[i+1];
        dp[i]= min(take, notTake);
    }
    cout<<dp[0]<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}