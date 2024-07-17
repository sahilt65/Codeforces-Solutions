#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n, m;
    cin>>n>>m;
    vector<ll> v(n);
    ll prod = 1;
    for(int i = 0; i<n; i++) {
        cin>>v[i];
        prod = prod * v[i];
    }
    string s;
    cin>>s;

    int left = 0;
    int right = n-1;
    for(int i = 0; i<n-1; i++){
        if(s[i] == 'L') left++;
        else right--;
    }

    vector<int> b(n);
    b[n-1] = v[left] % m;

    for(int i = n-2; i>=0; i--){
        if(s[i] == 'L'){
            left--;
            b[i] = (b[i+1] * v[left]) % m;
        }else{
            right++;
            b[i] = (b[i+1] * v[right]) % m;
        }
    }

    for(int i = 0; i<n; i++) cout<<b[i]<<" ";
    cout<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}