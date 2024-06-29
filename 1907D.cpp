#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<vector<ll> > v(n, vector<ll>(2));
    for(int i = 0; i<n; i++) cin>>v[i][0]>>v[i][1];

    ll l = 0, h = 1e9, leftK = 0, rightK = 0, k = 0, f = 0;

    while(l < h) {
        k = l +(h - l)/2;  // k is mid
        leftK = 0, rightK = k, f = 0;
        for(ll i = 0 ; i < n; i++) {
            if (rightK < v[i][0] || v[i][1] < leftK){
                f=1;
                break;   
            }
            leftK = max(leftK, v[i][0]);
            rightK = min(rightK, v[i][1]);
            leftK = max(0LL, leftK-k);
            rightK = rightK+k;
        }
        
        if(f == 0) 
            h = k;
        else
            l = k+1;
    }

    cout<<l<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}