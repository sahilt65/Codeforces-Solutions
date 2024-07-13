#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n, m, k; 
    cin >> n >> m>> k; 
    string a; 
    cin >> a;
    int currIndex = m - 1, w = 0, f = 0;
    for (int i = 0; i < a.size(); i++){
        char action = a [i];
        if(action == 'L'){
            currIndex = m;
        }else if(action == 'W'){
            if(currIndex <= 0) w++;
        }else{
            if(currIndex <= 0) f++;
        }
        currIndex--;
    }
    if (w > k) f++; 
    cout << (f!= 0? "NO" : "YES")<< endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}