#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    string s1, s2;
    cin>>s1;
    cin>>s2;

    int pos = n-1;
    bool found = false;
    for(int i = 1; i<n; i++){
        if(s1[i] == '1' && s2[i-1] == '0'){
            pos = i;
            found = true;
            break;
        }
    }

    if(found) pos--;

    pos = max(0, pos);
    string ans = "";
    for(int i = 0; i<=pos; i++) ans += s1[i];
    for(int i =  pos; i<n; i++) ans += s2[i];
    int cnt = 0;
    while(pos >= 1){
        if(s1[pos] == s2[pos-1]){
            cnt++;
        }else{
            break;
        }
        pos--;
    }
    cnt++;
    cout<<ans<<endl;
    cout<<cnt<<endl;
}


int main(){
    int t;
    cin>>t;

    while(t--) solve();
}

