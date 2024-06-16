#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n,m,x;
    cin>>n>>m>>x;
    vector<ll> v(m);
    vector<char>ch(m);
    for(int i=0;i<m;i++){
        cin>>v[i]>>ch[i];
    }
    set<ll>ans;
    ans.insert(x);
    set<ll>res;
    for(int i=0;i<m;i++){
        if(ch[i]=='0'){
            set<ll>tans;
            for(auto &it:ans){
                ll a = it+v[i];
                if(a>n) a -= n;
                tans.insert(a);
                if(i == m-1){
                    res.insert(a);
                }
            }
            ans=tans;
        }
        else if(ch[i]=='1'){
            set<ll>tans;
            for(auto &it:ans){
                ll a=it-v[i]+n;
                if(a>n)a-=n;
                tans.insert(a);
                if(i==m-1){
                    res.insert(a);
                }
            }
            ans=tans;
        }
        else{
            set<ll>tans;
            for(auto &it:ans){
                ll a=it+v[i];
                if(a>n)a-=n;
                tans.insert(a);
                if(i==m-1){
                    res.insert(a);
                }
                a=it-v[i]+n;
                if(a>n)a-=n;
                tans.insert(a);
                if(i==m-1){
                    res.insert(a);
                }
            }
            ans=tans;
        }
    }
    cout<<res.size()<<"\n";
    for(auto &it:res){
        cout<<it<<" ";
    }
    cout<<"\n";
}


int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}