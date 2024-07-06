#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, x;
    cin>>n>>x;
    vector<ll> b(n);
    vector<pair<ll,ll> > a(n);
    vector<ll> a1(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i].first;
        a[i].second = i;
        a1[i] = a[i].first;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i<n; i++) cin>>b[i];
    sort(b.begin(), b.end());

    
    vector<ll> ans(n);
    int f = 1;
    for(int i = x; i>0; i--){
        ans[a[n-i].second] = b[x-i];
        f &= (ans[a[n-i].second] < a1[a[n-i].second]);
    }

    for(int i= x+1, j = 0; i<=n; i++, j++){
        ans[a[j].second] = b[x+j];
        f &= (ans[a[j].second] >= a1[a[j].second]);
    }

    if(f){
        cout<<"YES"<<endl;
        for(int i = 0; i<n; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}