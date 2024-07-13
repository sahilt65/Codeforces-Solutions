#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;

    stack<char> st1, st2;
    ll c1 = 0, c2 = 0;
    vector<int> v;
    for(int i = 0; i<n; i++){
        if(s[i] == '('){
            if(!st2.empty() && st2.top() == ')'){
                st2.pop();
                v.push_back(2);
                c2++;
            }else{
                st1.push('(');
                v.push_back(1);
                c1++;
            }
        }else{
            if(!st1.empty() && st1.top() == '('){
                st1.pop();
                v.push_back(1);
            }else{
                st2.push(')');
                v.push_back(2);
            }
        }
    }

    if(st1.empty() && st2.empty()){

        if(c1 > 0 && c2 > 0){
            cout<<2<<endl;
        }else{
            cout<<1<<endl;
        }

        for(int i = 0; i<v.size(); i++){
            if(c1 == 0 || c2 == 0){
                cout<<1<<" ";
            }else{
                cout<<v[i]<<" ";
            }
        }
        cout<<endl;

    }else{
        cout<<"-1"<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}