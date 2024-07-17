#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

ll countZeroes(ll n){
    ll c=0;
    while(n>0){
        if(n%10!=0)break;
        c++;
        n/=10;
    }
    return c;
}
ll countDigits(ll n){
    ll c=0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}

void solve() {
    int n, m;
    cin>>n>>m;

    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    int sum = 0;
    vector<int> zeroes(n);
    for(int i=0;i<n;i++){
        sum+=countDigits(v[i]);
        zeroes[i]=countZeroes(v[i]);
    }
    
    sort(zeroes.rbegin(),zeroes.rend());
    for(int i=0;i<n;i+=2){
        sum-=zeroes[i];
    }


    if(sum >= m + 1){
        cout<<"Sasha"<<endl;
    }else{
        cout<<"Anna"<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}