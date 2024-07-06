#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll check(ll n, ll k, vector<ll> v, ll x){
    for(int i = 0; i<n; i++){
        if(v[i]<x){
            ll diff=x-v[i];
            if(k<diff){
                return -1;
            }
            else{
                k-=diff;
            }
        }
        v[i]-=x;
    }
    ll c=0;
    for(int i = 0; i<n; i++){
        if(v[i]>0)c++;
    }
    if(c>n)c=n;
    return k+c;
}
void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i = 0; i<n; i++) cin>>v[i];
    ll h=1e13;
    ll l=1;
    ll ans=0;
    while(l<=h){
        ll mid=(l+(h-l)/2);
        ll res=check(n,k,v,mid);
        if(res!=-1){
            ans=max(ans,1+res+((mid-1)*n));
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}