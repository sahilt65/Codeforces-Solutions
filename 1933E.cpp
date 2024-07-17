#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    ll n;
    cin>>n;
    vll v(n);
    for(int i = 0; i<n; i++) cin>>v[i];
    vll pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+v[i];
    }
    ll q;
    cin>>q;
    while(q--){
        ll l,u;
        cin>>l>>u;
        l--;
        ll x=u;
        if(l>0)x+=pre[l-1];
        int lb=(lower_bound(pre.begin(),pre.end(),x) - pre.begin());
        if(lb<=l){
            cout<<l+1<<" ";
        }
        else if(lb>=n){
            cout<<n<<" ";
        }
        else{
            if(abs(pre[lb]-x)<=abs(pre[lb-1]-x)){
                cout<<lb+1<<" ";
            }
            else{
                cout<<lb<<" ";
            }
        }
    }
    cout<<"\n";
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}