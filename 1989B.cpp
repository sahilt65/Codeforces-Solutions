#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    string a,b; cin>>a>>b;
 
    ll best = 1e9 + 10;
 
    for(int i = 0; i<b.size(); i++){
        ll x = 0, y = i;
        while(x<(int)a.size() and y<(int)b.size()){
            if(a[x] == b[y]) y++;
 
            x++;
        }
 
        best = min(best, i + (int)b.size() - y);
    }
 
 
    cout<<(int)a.size() + best<<'\n';
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}