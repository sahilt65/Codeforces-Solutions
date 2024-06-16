#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    int mini = INT_MAX;
    int miniIdx = 0;

    for(int i = 0; i<n; i++){
        cin>>v[i];
        if(mini > v[i]){
            mini = v[i];
            miniIdx = i;
        }
    }

    int ans = miniIdx;

    for(int i = miniIdx+1; i<n; i++){
        if(v[i] < v[i-1]){
            ans = -1;
            break;
        }
    }
    cout<<ans<<endl;
}


int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}