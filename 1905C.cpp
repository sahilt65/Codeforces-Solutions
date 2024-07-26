#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin>>n;

    string s;
    cin>>s;

    vll lexIndex;

    for(int i = 0; i<n; i++){
        while(!lexIndex.empty() && (s[i] > s[lexIndex.back()])) lexIndex.pop_back();
        lexIndex.push_back(i);
    }

    ll size = lexIndex.size();
    ll first = s[lexIndex[0]];
    ll dup = 0;

    for(ll i = 0; i<size; i++){
        if(s[lexIndex[i]] == first) dup++;
    }

    for(ll i = 0; i<size/2; i++){
        swap(s[lexIndex[i]], s[lexIndex[size - i - 1]]);
    }

    if(is_sorted(s.begin(), s.end())) cout<<size - dup<<endl;
    else cout<<"-1"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}