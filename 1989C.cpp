#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>b[i];
    ll x = 0, y = 0;

    //Not Equal Case
    for(int i = 0; i<n; i++){
        if(a[i] != b[i]){
            if(a[i] > b[i]) x += a[i];
            else y += b[i];
        }
    }

    //Equal But both are 1
    for(int i = 0; i<n; i++){
        if(a[i] == 1 && b[i] == 1){
            if(x < y) x++;
            else y++;
        }
    }

    //Equal but both are -1
    for(int i = 0; i<n; i++){
        if(a[i] == -1 && b[i] == -1){
            if(x > y) x--;
            else y--;
        }
    }

    ll ans = min(x, y);
    cout<<ans<<endl;


}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}