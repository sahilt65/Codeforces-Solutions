#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;

        int min_f_a = numeric_limits<int>::max();

        // Check all integer values from 1 to 10 for a
        for (int a = 1; a <= 10; ++a) {
            int f_a = abs(a - x1) + abs(a - x2) + abs(a - x3);
            if (f_a < min_f_a) {
                min_f_a = f_a;
            }
        }

        cout << min_f_a << endl;
    }

    return 0;
}
