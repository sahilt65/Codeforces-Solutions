#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    ll penalty= 0;

    int sl = INT_MAX;
    int tl = INT_MAX;
    for(int i = 0; i<n; i++){
        if(sl > tl){
            swap(sl, tl);
        }

        if(a[i] <= sl){
            sl = a[i];
        }else if(a[i] <= tl){
            tl = a[i];
        }else{
            sl = a[i];
            penalty++;
        }
    }

    cout<<penalty<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}