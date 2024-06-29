#include <iostream>
#include <vector>
using namespace std;

int maxRounds(vector<int>& a, int n, int l, int r) {
    int rounds = 0;
    int currentSum = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum = 0;
        for (int j = i; j < n; ++j) {
            currentSum += a[j];
            if (currentSum >= l && currentSum <= r) {
                rounds++;
                break;  // Once we win this round, move to the next starting point
            }
            if (currentSum > r) break;  // If the sum exceeds r, no point in continuing further
        }
    }
    return rounds;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        cout << maxRounds(a, n, l, r) << endl;
    }
    
    return 0;
}
