#include<bits/stdc++.h>
using namespace std;

#define ll long long


void solve(){
    ll n, k;
    cin>>n>>k;

    vector<ll> v(n);
    ll sum = 0;
    for(int i = 0; i<n; i++) {
        cin>>v[i];
        sum+=v[i];
    }

    if(sum <= k){
        cout<<n<<endl;
        return;
    }
    int ans = 0;
    if(k%2 == 0){
        ll l = k/2;
        ll r = k/2;
        int x = 0;
        for(int i =0; i<n; i++){
            if(v[i] <= l){
                l -= v[i];
                ans++;
            }else{
                break;
            } 
        }
        for(int i =n-1; i>=0; i--){
        
            if(v[i] <= r){
                r -= v[i];
                ans++;
            }else{
                break;
            }
        }
        cout<<ans<<endl;
    }else{
        ll l = k/2 + 1;
        ll r = k/2;
        int x = 0;
        for(int i =0; i<n; i++){
            if(v[i] <= l){
                l -= v[i];
                ans++;
            }else{
                break;
            } 
        }
        for(int i =n-1; i>=0; i--){
        
            if(v[i] <= r){
                r -= v[i];
                ans++;
            }else{
                break;
            }
        }
        cout<<ans<<endl;
    }

    // bool first = true;
    // ll ans = 0;
    //Brute Force
    // ll i = 0, j = n-1;
    // while(k--){
    //     if(first){
    //         v[i]--;
    //         if(v[i] == 0){
    //             ans++;
    //             i++;
    //         }
    //         first = false;
    //     }else{
    //         v[j]--;
    //         if(v[j] == 0){
    //             ans++;
    //             j--;
    //         }
    //         first = true;
    //     }
    // }
    // cout<<ans<<endl;


}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}