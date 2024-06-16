#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n, c, d;
    cin>>n>>c>>d;

    map<ll, ll> mp;
    for(int i =0; i<n; i++) {
        int ele;
        cin>>ele;
        mp[ele]++;
    }

    vector<ll> v;
    ll ans = 0;
    for(auto i : mp){
        v.push_back(i.first);
        ans += (i.second - 1) * c;
    }
    sort(v.begin(), v.end());
    ll temp = LLONG_MAX;
    for(int i = v.size() - 1; i>=0; i--){
        ll currIdx = i+1;
        ll size = v[i];

        ll add = (size - currIdx) * d;
        ll remove = (v.size() - currIdx) * c;

        temp = min(ans + add + remove, temp);
        
    }
    
    temp = min(temp, (n*c+d));
    cout<<temp<<endl;

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}