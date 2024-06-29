#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool neverTied(ll x1, ll y1, ll x2, ll y2) {
    if((x2 < y2 && x1 < y1) || (y2 < x2 && y1 < x1)){
        return true;
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        
        if (neverTied(x1, y1, x2, y2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
