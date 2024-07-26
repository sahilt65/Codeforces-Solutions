#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
WRONG ANS
int main() {
    ll t;
    cin >> t;
 
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;
 
        vector<ll> petals(n);
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for(int i = 0; i<n; i++){
            petals[i] = a[i] * b[i];
        }
 
        sort(petals.begin(), petals.end());
 
        long long max_petals = 0;
        long long current_sum = 0;
        int start = 0;
 
        for (int end = 0; end < n; ++end) {
            current_sum += petals[end];
 
            while (current_sum > m || (end > start && petals[end] - petals[start] > 1)) {
                current_sum -= petals[start];
                start++;
            }
 
            if (current_sum <= m) {
                max_petals = max(max_petals, current_sum);
            }
        }
 
        cout << max_petals << endl;
    }
 
    return 0;
}