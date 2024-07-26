#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n, k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i = 0; i<n;i++) cin>>v[i];

    int last = n-1;
    k = min(k, n);

    for(int i =0; i<k; i++){
        if(v[last] > n){
            cout<<"No"<<endl;
            return;
        }

        last += n - v[last];
        if(last >= n){
            last -= n;
        }
    }

    cout<<"Yes"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}