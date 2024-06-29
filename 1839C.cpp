#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    reverse(v.begin(), v.end());
    if(v[0] == 1) {
        cout<<"NO"<<endl;
        return;
    }
    vector<int> ans;
    int curr = 1;
    for(int i = 1; i<n; i++){
        if(v[i] != v[i-1]){
            ans.push_back(curr);
            curr = 1;
        }else{
            ++curr;
        }
    }
    ans.push_back(curr);

    cout<<"YES"<<endl;
    for(int i = 0; i<ans.size(); i+=2){
        if(i + 1 < ans.size()){
            for(int j = 0; j<ans[i] - 1; j++) cout<<0<<" ";
            for(int j = 0; j<ans[i+1]; j++) cout<<"0"<< " ";

            cout<<ans[i+1]<<" ";
        }else{
            for(int j = 0; j<ans[i]; j++){
                cout<<"0"<<" ";
            }
        }

    }

    cout<<endl;
}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}