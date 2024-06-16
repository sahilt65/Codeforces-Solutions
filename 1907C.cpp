#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int maxi = 0;
    unordered_map<char, int> mp;
    for(auto i : s) {
        mp[i]++;
        maxi = max(mp[i], maxi);
    }
    int ans = 0;
    if(maxi > n/2){
        ans = n - (n - maxi) * 2;
    }else{
        ans = n%2;
    }

    cout<<ans<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}