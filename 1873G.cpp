#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    ll ans = 0;
    vector<int> v;
    int cntB = 0;
    int curr = 0;
    for(int i =0; i<n; i++){
        if(s[i] == 'A') curr++;
        if(s[i] == 'B') {
            cntB++;
            if(curr > 0) v.push_back(curr);
            curr = 0;
        }
    }

    if(curr > 0) v.push_back(curr);
    
    
    sort(v.begin(), v.end());
    int i = v.size() - 1;
    while(i >= 0 && cntB-- > 0){
        ans += v[i];
        i--;
    }

    cout<<ans<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}