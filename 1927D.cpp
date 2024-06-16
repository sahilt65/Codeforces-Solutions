#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i<n; i++) cin>>v[i];

    vector<int> diff;

    for(int i = 0; i<n-1; i++){
        if(v[i] != v[i+1]) diff.push_back(i);
    }

    int q;
    cin>>q;

    while(q--){
        int l, r;
        cin>>l;
        cin>>r;
        l--;
        r--;
        ll lb=lower_bound(diff.begin(),diff.end(),l)-diff.begin();
        if(lb<diff.size()&&diff[lb]<r){
            cout<<diff[lb]+1<<" "<<diff[lb]+2<<"\n";
        }
        else{
            cout<<"-1 -1\n";
        }
    }

}
int main() {
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}