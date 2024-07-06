#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mex(vector<ll> &arr) {
 
	set<ll> s;
	for(ll i = 0; i <= arr.size(); i++) s.insert(i);
	for(auto i : arr) s.erase(i);
 
	return *(s.begin());
 
}
void solve() {
    int n;
    cin>>n;
    vector<ll> v(n);

    for(int i = 0; i<n; i++) cin>>v[i];

    ll m = mex(v);
 
	while(m != -1) {
		cout << m << endl;
		cin >> m;
		if(m == -1) break;
	}
}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}