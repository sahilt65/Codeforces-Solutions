#include<bits/stdc++.h>

using namespace std;

#define ll long long
void solve () {
    ll n;
        cin>>n;
 
        vector<ll> v(n);
 
        for(int i=0; i<n; i++){
            cin>>v[i];
            if(i%2==0){
                v[i]*=-1;
            }
        }
        set<ll> s;
        bool ans = false;
        bool status = false;
        ll ps = 0;
        s.insert(ps);
        for(int i=0; i<n; i++){
            ps+=v[i];
            if(s.count(ps)>0){
                cout<<"YES\n";
                status = true;
                break;
            }else{
                s.insert(ps);
            }
        }
        if(!status){
            cout<<"NO\n";
        }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}