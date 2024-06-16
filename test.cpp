#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ump unordered_map
#define omp unordered_map
void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    ump<ll, ll> mp;
    for(int i = 0; i<n; i++) mp[v[i]] = 1;
    ll mex = 0;
    for(int i = 0; i<1e5+5; i++){
        if(mp[i] == 0) {
            mex = i;
            break;
        }
    }

    if(mex == 0){
        cout<<"2"<<endl;
        cout<<"1 1\n";
        cout<<"2 "<<n<<endl;
    }
    ll left = 0;
    mp.clear();
    vector<pair<ll, ll> > ans;
    for(ll i = 0; i<n; i++){
        if(v[i] < mex) {
            mp[v[i]] = 1;
        }

        if(mp.size() == mex){
            ans.push_back(make_pair(left+1, i+1));
            left = i+1;
            mp.clear();
        }
    }

    ans[ans.size() -1 ].second = n;
    if(ans.size() < 2){
        cout<<"-1\n";
    }else{
        cout<<ans.size()<<endl;
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}