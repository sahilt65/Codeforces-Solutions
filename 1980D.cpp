#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll __gcd(ll a, ll b) {
   if (b == 0)
   return a;
   return __gcd(b, a % b);
}

bool check(vector<ll> &v, ll inIndex){
    ll n = v.size();
    vector<ll> temp;
    for(int i = 0; i<n; i++){
        if(i != inIndex){
            temp.push_back(v[i]);
        }
    }

    ll g[n-1];
    for(int i = 0; i<n-1; i++){
        g[i] = __gcd(temp[i], temp[i+1]);
    }

    if(is_sorted(g, g+n-2)){
        return true;
    }
    return false;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    vector<ll> g(n-1);
    for(int i = 0; i<n-1; i++){
        g[i] = __gcd(v[i], v[i+1]);
    }
    if(is_sorted(g.begin(), g.end())){
        cout<<"YES"<<endl;
        return;
    }

    ll inIndex = 0;
    for(int i = 0; i<n-2; i++){
        if(g[i] > g[i+1]){
            inIndex = i;
            break;
        }
    }

    if(check(v, inIndex) || check(v, inIndex+1) || check(v, inIndex+2)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    return;
}

int main() {
    int t; cin>>t; while(t--) solve();
    return 0;
}