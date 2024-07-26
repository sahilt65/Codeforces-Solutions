#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    int maxi = *max_element(v.begin(), v.end());
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(v[i] == maxi){
            cnt++;
        }
    }
    if(cnt%2 != 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}