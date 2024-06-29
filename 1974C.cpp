#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n;
    cin>>n;

    vector<ll> v(n);
    for(int i = 0; i<n; i++) cin>>v[i];
    ll ans = 0;
    for(int i = 0; i<3; i++){
        map<pair<ll, ll>, vector<ll>> m;

        for(int j = 0; j<n-2; j++){
            if(i == 0){
                m[{v[j+1], v[j+2]}].push_back(v[j+i]);
            }else if (i == 1){
                m[{v[j], v[j+2]}].push_back(v[j+i]);
            }else{
                m[{v[j], v[j+1]}].push_back(v[j+i]);
            }
        }
        
        for(auto x : m){
            sort(x.second.begin(), x.second.end());
            vector<ll> tmp;
            ll cnt = 1;

            for(int k = 0; k < x.second.size(); k++){
                if(x.second[k] == x.second[k-1]) cnt++;
                else{
                    tmp.push_back(cnt);
                    cnt = 1;
                }
            }

            tmp.push_back(cnt);
            if(tmp.size() < 2) continue;

            ll res = x.second.size();
            res = res * (res - 1)/2;

            ans += res;

            for(auto y : tmp){
                ans -= (y * (y-1)/2);
            }
        }
        m.clear();
    }
    cout<<ans<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}