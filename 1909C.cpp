#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<ll> c(n), diff;
    vector<pair<ll, char> > intervals;

    for(int i = 0; i<n; i++){
        ll x;
        cin>>x;
        intervals.push_back( { x, 'l' } );
    }
    for(int i = 0; i<n; i++){
        ll x;
        cin>>x;
        intervals.push_back( { x, 'r' } );
    }
    for(int i = 0; i<n; i++) cin>>c[i];

    sort(intervals.begin(), intervals.end());

    stack<ll> st;

    for(int i =0; i<intervals.size(); i++){
        if(intervals[i].second == 'l'){
            st.push(intervals[i].first);
        }else{
            diff.push_back(intervals[i].first - st.top());
            st.pop();
        }
    }

    sort(diff.begin(), diff.end());
    sort(c.rbegin(), c.rend());
    ll ans = 0;
    for(int i = 0; i<n; i++){
        ans += c[i] * diff[i];
    }

    cout<<ans<<endl;
}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}