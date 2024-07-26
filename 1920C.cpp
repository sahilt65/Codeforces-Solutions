#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n; 
    cin >> n;

    int A[n];
    for (int &i : A)
        cin >> i;
    
    int ans = 0;
    for (int k = 1; k <= n; k++){
        if (n % k == 0){
            int g = 0;
            for (int i = 0; i + k < n; i++)
                g = __gcd(g, abs(A[i + k] - A[i]));
            ans += (g != 1);
        }
    }
    cout<<ans<<"\n";
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}