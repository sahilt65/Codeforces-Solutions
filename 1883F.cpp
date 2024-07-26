#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    ll n;
	cin >> n;
 
	ll arr[n];
	for(ll i = 0; i < n; i++) cin >> arr[i];
 
	set<ll> first;
	set<ll> s;
	set<ll> last;
	map<ll, ll> hm;
 
	for(ll i = 0; i < n; i++) {
		if(s.count(arr[i]) == 0) first.insert(i);
		s.insert(arr[i]);
		hm[arr[i]] = i;
	}
 
	for(auto i : hm) last.insert(i.second);
	ll ans = 0;
	ll cnt = 0;
	for(ll i = n - 1; i >= 0; i--) {
 
		if(last.count(i)) cnt++;
		if(first.count(i)) ans += cnt;
 
	}
 
	cout << ans << '\n';
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}