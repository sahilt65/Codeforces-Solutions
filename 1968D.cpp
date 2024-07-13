#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

ll findMax(ll n, ll k, vector<ll> p, vector<ll> a, ll currPosition){
    ll ans = 0;
    ll sum = 0;

    vector<bool> vis(n, false);

    while(!vis[currPosition] && k > 0){
        vis[currPosition] = true;
        ans = max(ans, sum + (k * a[currPosition]));
        sum += a[currPosition];
        k--;
        currPosition = p[currPosition] - 1;
    }

    return ans;
}

void solve() {
    ll n, k, pb, ps;
    cin>>n>>k>>pb>>ps;

    vector<ll> p(n);
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>p[i];
    for(int i = 0; i<n; i++) cin>>a[i];
    pb--;
    ps--;

    ll bodya = findMax(n, k, p, a, pb);
    ll sasha = findMax(n, k, p, a, ps);

    if(bodya > sasha){
        cout<<"Bodya"<<endl;
    }else if(bodya < sasha){
        cout<<"Sasha"<<endl;
    }else{
        cout<<"Draw"<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}