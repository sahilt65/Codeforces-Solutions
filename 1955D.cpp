#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    ll n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    map<ll, ll> mp1, mp2;
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<m; i++) {
        cin>>b[i];
        mp2[b[i]]++;
        mp1[a[i]]++;
    }
    int ans = 0;
    int curr = 0;
    for(auto i : mp1){
        curr+= min(i.second, mp2[i.first]);

    }

    if(curr >= k) ans++;

    for(int i = m; i<n; i++){

        int prev = min(mp1[a[i-m]], mp2[a[i-m]]);
        //removing forward element
        mp1[a[i-m]]--;
        int now = min(mp1[a[i-m]], mp2[a[i-m]]);

        if(now > prev) curr++;
        else if(now < prev) curr--;

       
        prev = min(mp1[a[i]], mp2[a[i]]);
        //adding new element
        mp1[a[i]]++;
        now = min(mp1[a[i]], mp2[a[i]]);

        if(now > prev) curr++;
        else if(now < prev) curr--;

        if(curr >= k) ans++;
    }

    cout<<ans<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}