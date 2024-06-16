#include<bits/stdc++.h>
using namespace std;
#define ll long long

string numtobit(ll x){
    string bits="";
    while(x>0){
        char bit='0'+(x%2);
        bits+=bit;
        x/=2;
    }
    while(bits.size()<31)bits+="0";
    return bits;
}

void solve(){
    int n;
    cin>>n;

    vector<ll> v(n);
    map<string, ll> mp;

    for(int i = 0; i<n; i++){
        cin>>v[i];
        string bits = numtobit(v[i]);
        mp[bits]++;
    }
    ll ans=n;
    for(int i = 0; i<n; i++){
        string currBits = numtobit(v[i]);
        string flipBit = "";
        ll x = v[i];
        if(mp[currBits] == 0) continue;
        
        while(x>0){
            char bit='0' + (x%2);
            if(bit=='0')
            flipBit +="1";
            else flipBit +="0";
            x/=2;
        }
        
        while(flipBit.size()<31)flipBit+="1";

        if(mp[flipBit]>0){
            mp[flipBit]--;
            mp[currBits]--;
            ans--;
        }
        
    }

    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}