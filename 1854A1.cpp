#include <iostream>
#include <bits/stdc++.h>
// #include "utilities.cpp"
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
int row[] = {1,0};
int col[] = {0,1};
const int mod = 1e9 + 7;
// const int mod = 998244353;


void solve(){   

    int n;
    cin>>n;

    int pos = 0;
    int neg = 0;
    int zero = 0;

    vector<int> a(n);

    forn(i,0,n){
        cin>>a[i];
        if(a[i] < 0) neg++;
        else if(a[i] > 0) pos++;
        else zero++;
    }

    vpp ans;

    if(pos + zero == n){
        forn(i,1,n){
            ans.pb({i, i-1});
            a[i] += a[i-1];
        }
    
    }else if(neg+zero == n){

        for(int i=n-2; i>=0; i--){
            ans.pb({i, i+1});
            a[i] += a[i+1];
        }

    }else{

        int maxiPos = 0;
        int ind = max_element(all(a)) - a.begin();
        forn(i,0,n) maxiPos = max(maxiPos, a[i]);

        forn(i,0,10){
            ans.pb({ind, ind});
            maxiPos += maxiPos;
        }

        ans.pb({0, ind});
        a[0] += maxiPos;

        forn(i,1,n){

            while(a[i] < a[i-1]){
                a[i] += a[i-1];
                ans.pb({i, i-1});
            }
        }
    }

    cout<<ans.size()<<'\n';
    for(auto i: ans){
        cout<<i.first+1<<' '<<i.second+1<<'\n';
    }
}     



signed main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;

}