#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll LCM=(a*b)/__gcd(a,b);
        if(LCM==b){
            cout<<b*(b/a)<<endl;
        }
        else{
            cout<<LCM<<endl;
        }
    }
}