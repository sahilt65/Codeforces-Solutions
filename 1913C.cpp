#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    map < ll , ll > ma,val;
    ma[0] = 1ll;
    for(ll i = 1ll ; i < 30 ; i++) {
        ma[i] = ma[i-1ll]*2ll;
    }
 
    ll n,a,b;
    cin>>n;
    for(ll i = 0 ; i < n ; i++) {
        cin>>a>>b;

        if(a == 1) {
            val[ma[b]]++;
        }
        else {
 
            for(ll i = 30 ; i >= 0 ; i--) {
                if(b >= ma[i] and b!=0) {
                    if(val.count(ma[i])) {
                        b-=min(b/ma[i],val[ma[i]])*ma[i];
                    }
                }
            }
            if(b == 0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            
        }
        if(i == n-1)
            return ;
        
    }
}


int main() {
    solve();
    return 0;
}