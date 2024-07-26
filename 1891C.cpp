#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll sum = 0;
    for(ll i = 0; i<n; i++){
        cin>>v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    if(sum%2 != 0) ans++;

    ans += sum/2;

    sum  = sum/2;
    ll j = n-1;
    while(sum>0){
        sum-=v[j];
        ans++;
        j--;
    }

    cout<<ans<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}