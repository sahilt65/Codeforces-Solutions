#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>b[i];

    vector<pair<int, int> > v;
    for(int i = 0; i<n; i++){
        v.push_back({a[i] + b[i],i});
    }

    sort(v.rbegin(), v.rend());
    int alice = 1;
    for(int i =0; i<n; i++){
        if(alice){
            a[v[i].second]--;
            b[v[i].second] = 0;
            alice = 0;
        }else{
            a[v[i].second] = 0;
            b[v[i].second]--;
            alice = 0;
        }
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        ans +=(a[i]-b[i]);
    }

    cout<<ans<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}