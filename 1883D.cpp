#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll q;
    cin>>q;

    multiset<ll> right, left;
    while(q--){
        char c;
        cin>>c; 
        ll a,b;
        cin>>a>>b;

        if(c == '+'){
            left.insert(a);
            right.insert(b);
        }else{
            left.erase(left.lower_bound(a));
            right.erase(right.lower_bound(b));
        }

        if(left.empty()) cout<<"NO"<<endl;
        else{
            auto it = left.end();
            it--;

            if((*it) > *(right.begin())){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}
int main() {
    solve();
    return 0;
}