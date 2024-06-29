#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;

    vector<ll> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    ll mini = *min_element(v.begin(), v.end());
    ll maxi = *max_element(v.begin(), v.end());

    vector<ll> ans;
    while(mini != maxi){
        if(maxi % 2 == mini % 2) ans.push_back(0);
        else if(maxi%2 == 0){
            ans.push_back(1);
            mini+=1;
            maxi+=1;
        }else{
            ans.push_back(0);
        }

        maxi /= 2;
        mini /= 2;
    }
    cout<<ans.size()<<endl;
    if(ans.size() <= n && ans.size()!= 0){
        for(auto i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}