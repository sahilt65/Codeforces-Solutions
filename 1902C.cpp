#include<bits/stdc++.h>

using namespace std;

#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
    unordered_map<ll, ll> mp;
    if(n==1){
        cout<<n<<endl;
        return;
    }
    for(int i = 0; i<n; i++){
        cin>>v[i];
        mp[v[i]]++;
    }

    sort(v.begin(), v.end());
    ll gcd = v[n-1] - v[n-2];

    for(int i = n-3; i>=0; i--){
        gcd = __gcd(gcd, v[n-1]-v[i]);
    }
    
    ll ans = 0;
    for(int i = 0; i<n; i++){
        ans += (v[n-1]-v[i])/gcd;
    }
    
    ll curr = v[n-1];
    
    while(mp.find(curr) != mp.end()){
        curr -= gcd;
    }
    
    ans += (v[n-1]-curr)/gcd;

    cout<<ans<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}