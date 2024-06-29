#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n, m;
    cin>>n>>m;
    ll ans = 0;
    for(ll val=1;val<=m;val++) {
    	ll prd = val*val;
    	ll min = prd - val;
    	while(min < 1) min += prd;
    	if(min <= n) {
    		ans++;
    		long left = n - min;
    		ans += left / prd;
    	}
    }
    cout<<(ans)<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}