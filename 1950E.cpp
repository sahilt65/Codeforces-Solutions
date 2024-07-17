#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin>>n;

    string s;
    cin>>s;

    for(int i = 1; i<=n; i++){
        if(n%i == 0){
            int sat = 2;

            //Check From Starting
            for(int j = 0; j<i; j++){
                for(int k = j+i; k<n; k+=i){
                    if(s[k] != s[j]){
                        sat--;
                    }

                    if(sat<0) break;
                }
            }

            if(sat>0){
                cout<<i<<endl;
                return;
            }

            sat = 2;
            //Check for string from back
            for(int j = n-i; j<n; j++){
                for(int k = j-i; k>=0; k-=i){
                    if(s[k] != s[j]){
                        sat--;
                    }

                    if(sat<0) break;
                }
            }

            if(sat>0){
                cout<<i<<endl;
                return;
            }
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}



    