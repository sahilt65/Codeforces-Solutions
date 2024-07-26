#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
 
	vector<long long> pref(n + 1);
	for (int i = 0; i < n; i++){
		pref[i + 1] = pref[i] + a[i];
	}
 
	vector<int> dp(n + 1);
	int s = 0;
	int j = -1;
	for (int i = 0; i < n; i++){
		dp[i + 1] = max(dp[i + 1], dp[i]);
		if (j < i){
			j = i;
			s = 0;
		}
		while(j < n && s < l){
			s += a[j++];
		}
		if (s >= l && s <= r){
			dp[j] = max(dp[j], dp[i] + 1);
		}
		s -= a[i];
	}
 
	cout << dp[n] << '\n';
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}