#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;

    int ans = (int)1e9 + 7;
    for(int i=0;i<n-1;i++) {
        int num = (int)(s[i] - 48) * 10 + (int)(s[i + 1] - 48);
        int sum = 0;
        for(int j=0;j<i;j++) {
            if(s[j] == '0') {
                cout << 0 << "\n";
                return;
            }
            if(s[j] >= '2') sum += (int)s[j] - 48;
        }
        for(int j = i + 2;j<n;j++) {
            if(s[j] == '0') {
                cout << 0 << "\n";
                return;
            }
            if(s[j] >= '2') sum += (int)s[j] - 48;
        }
        if(num == 1 && sum > 0) num = sum;
        else num += sum;
        ans = min(ans, num);
    }
    cout << ans << "\n";
    
}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}