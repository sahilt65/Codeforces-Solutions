#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    if(n%2 == 0){
        cout<<"NO"<<endl;
        return;
    }
    if(n == 1){
        cout<<"YES\n1 2"<<endl;
        return;
    }
    
    ll i = n, j = n+1;
    vector<pair<ll, ll> > p;
    while(i != -1){
        p.push_back({i, j});
        i = i - 2;
        j++;
    }

    i = 2;
    ll x = 2*n;

    while(x != j-1){
        p.push_back({i, x});
        i += 2;
        x--;
    }
    
    cout<<"YES"<<endl;
    for(int i = 0; i<p.size(); i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }

}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}