#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    ll h, n;
    cin>>h>>n;

    vector<ll> a(n), c(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>c[i];
    
    ll low = 1;
    ll high = 1e12;
    ll ans = high;

    while(low<=high){
        ll mid = (low + high)/2ll;
        ll sum = 0;
        for(int i = 0; i<n; i++){
            ll tot = (mid - 1ll)/c[i];
            tot += 1ll;
            sum += (tot * a[i]);
            if (sum >= h)
            {
                break;
            }
        }

        if(sum >= h){
            ans = min(ans, mid);
            high = mid - 1ll;
        }else{
            low = mid + 1ll;
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