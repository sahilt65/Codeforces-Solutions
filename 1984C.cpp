#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    ll ans1 = 0, ans2 = 0;
    for(int i=0;i<n;i++) {
    	ll ans3 = ans1 + a[i];
    	ll ans4 = ans2 + a[i];
    	ll ans5 = abs(ans1 + a[i]);
    	ll ans6 = abs(ans2 + a[i]);
    	ans1 = max(max(ans3, ans4), max(ans5, ans6));
    	ans2 = min(min(ans3, ans4), min(ans5, ans6));
    }

    cout<<max(abs(ans1), abs(ans2))<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}