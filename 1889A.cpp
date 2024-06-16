#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin>>n;

    string s;
    cin>>s;

    deque<ll> dq;
    ll cnt0 = 0;
    for(ll i = 0; i<n; i++) {
        if(s[i] == '0') cnt0++;
        else cnt0--;
        dq.push_back(s[i] - '0');
    }
        

    if(n%2 != 0 || cnt0 != 0){
        cout<<"-1"<<endl;
        return;
    }
    vector<ll> ans;
    ll i = 0;
    while(!dq.empty()){
        if(dq.front() != dq.back()){
            dq.pop_front();
            dq.pop_back();
        }else if(dq.front() == 0){
            ans.push_back(i+dq.size());
            dq.push_back(0);
            dq.pop_front();
        }else{
            ans.push_back(i);
            dq.push_front(1);
            dq.pop_back();
        }
        i++;
    }

    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}