#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin>>n;
    set<int> st;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        st.insert(a);
    }

    vector<int> v;
    for(auto i : st) v.push_back(i);

    vector<int> res;
    res.push_back(v[0]);

    for(int i = 1; i<v.size(); i++){
        res.push_back(v[i] - v[i-1]);
    }

    int ans = 1;

    for(int i = res.size() - 2; i>=0; i--){
        if(res[i] == 1){
            ans = 1 - ans;
        }else{
            ans = 1;
        }
    }

    if(ans == 1){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}