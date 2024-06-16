#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 998244353;
void solve(){
    string s;
    cin>>s;
    int n = s.size();
    ll extra = 0;
    ll count = 0;
    ll ops = 1;
    for(int i = 0; i<n-1; i++){
        if(s[i] == s[i+1]){
            extra++;
        }else{
            count += extra;
            extra++;
            ops = (ops % mod * extra % mod)%mod;
            extra = 0;
        }
    }

    if(extra != 0){
        count += extra;
        extra++;
        ops = (ops % mod * extra % mod)%mod;
        extra = 0;
    }
    ll fact = 1;
    for(ll i = 1; i<=count; i++){
        fact = ((fact % mod) * (i % mod)) % mod;
    }

    ops = ((ops % mod) * (fact % mod)) % mod;

    cout<<count<<" "<<ops<<endl;
    
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}