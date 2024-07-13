#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    ll n;
    cin>>n;
    int ans = 0;
    if(n==1) {
        cout<<'a'<<endl;
        return;
    }
    if(n==2){
        cout<<"ab"<<endl;
        return;
    }
    if(n==1){
        cout<<"abc"<<endl;
        return;
    }

    for(ll i = 1; i<n; i++){
        if(n%i != 0){
            ans = i;
            break;
        }
    }
    char c = 'a';
    int cnt = ans;

    for(int i = 0; i<n; i++){
        cout<<c;
        c++;
        cnt--;
        if(cnt == 0){
            cnt = ans;
            c = 'a';
        }
        
    }
    cout<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}