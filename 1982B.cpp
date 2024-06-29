#include<bits/stdc++.h>
using namespace std;

#define ll long long


long long applyOperations(long long x, long long y, long long k) {
    for (long long i = 0; i < k; ++i) {
        x += 1;
        while (x % y == 0) {
            x /= y;
        }
    }
    return x;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        ll ans = applyOperations(x, y, k);
        cout << ans << endl;
    }

    return 0;
}
