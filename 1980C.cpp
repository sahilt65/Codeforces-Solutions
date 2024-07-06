#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>b[i];

    int op;
    cin>>op;
    vector<ll> v(op);
    map<ll, ll> mp2;
    for(int i = 0; i<op; i++) {
        cin>>v[i];
        mp2[v[i]]++;
    }
    int ok = false;
    for(int i = 0; i<n; i++){
        if(b[i] == v[op-1]) ok = true;
        if(a[i] != b[i]){
            if(mp2.find(b[i]) == mp2.end()){
                cout<<"NO"<<endl;
                return;
            }else{
                mp2[b[i]]--;
                if(mp2[b[i]] == 0) mp2.erase(b[i]);
            }
        }
    }
    
    if(mp2.size() > 0 && !ok) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}