#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n, k;
    cin>>n>>k;

    ll maxi = 0;
    vector<ll> v(n,0);
    int ind = 0;
    for(int i = n; i>0; i--) v[ind++] = i;
    for(int i = 0; i<n; i++){
        ll val = i+1;
        maxi += abs(v[i] - val);
    }

    if(k % 2 != 0 || k > maxi){

        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;

    //Even Case
    if(n%2 == 0){
        ll val = n-1;
        ll st = 0;
        ll end = n-1;
        ll mini = 1;
        maxi = n;


        while(st <= end){
            if(k >= val * 2){
                v[st] = maxi;
                v[end] = mini;
                st++;
                end--;
                maxi--;
                mini++;
                k -= val*2;
            }else{
                if(k%4 == 0){
                    v[end] = maxi;
                    end--;
                    maxi--;
                    val--;
                    continue;
                }
                v[st] = mini;
                v[end] = maxi;
                mini++;
                maxi--;
                st++;
                end--;
            }
            val -= 2;
        }

    }
    //Odd N case
    if(n%2 != 0){
        ll val = n-1;
        ll st = 0;
        ll end = n-1;
        ll mini = 1;
        maxi = n;


        while(st <= end){
            if(k >= val * 2){
                v[st] = maxi;
                v[end] = mini;
                st++;
                end--;
                maxi--;
                mini++;
                k -= val*2;
            }else{
                if(k%4 != 0){
                    v[end] = maxi;
                    end--;
                    maxi--;
                    val--;
                    continue;
                }
                v[st] = mini;
                v[end] = maxi;
                mini++;
                maxi--;
                st++;
                end--;
            }
            val -= 2;
        }
    }

    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<endl;
}



int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}