#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int tax = 0;
    for (int i = 0; i < n; ++i) {
        int buy = min(m, k);
        ans += 1ll * buy * (a[i] + tax);
        tax += buy;
        k -= buy;
    }
    cout << ans << '\n';
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}