#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    string d;
    cin>>d;

    int m;
    cin>>m;
    string l, r;
    cin>>l;
    cin>>r;

    int start = -1;

    for(int i = 0; i<m; i++){
        char left = l[i];
        char right = r[i];
        int range = start + 1;
        for(char c = left; c<=right; c++){
            int ind = d.find(c, range);

            if(ind == -1){
                cout<<"YES"<<endl;
                return;
            }

            start = max(ind, start);
        }
        
    }
    cout<<"NO"<<endl;
    return;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}