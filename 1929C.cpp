#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll k, x, a;
    cin>>k>>x>>a;

    ll curr = 1;
    ll real = a;
    for(int i = 1; i<x; i++){
        ll next = (curr)/(k-1);
        next++;
        curr += next;
        if(curr > a){
            cout<<"NO"<<endl;
            return;
        }
    }

    a -= curr;
    if(a<0) {
        cout<<"NO"<<endl;
        return;
    }

    a*=k;

    if(a > real){
        cout<<"YES"<<endl;
        return;
    }


    cout<<"NO"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}