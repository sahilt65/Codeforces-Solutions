#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n, k;
    cin>>n>>k;
    vector<ll> a(k);
    for(int i = 0; i<k; i++)  cin>>a[i];
    ll ans = 0;
    sort(a.begin(), a.end());
    ll cnt = 0;
    ll op = 0;
    for(int i = 0; i<k-1; i++){
        if(a[i] == 1) cnt++;
        else{
            op += (a[i] - 1);
            cnt += a[i];
        }
    }

    ans = op + cnt;
    cout<<ans<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}