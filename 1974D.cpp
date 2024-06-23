#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n; string t;
    cin >> n >> t;
    int x = 0, y = 0;
    for(auto i: t){
        if(i == 'N') y++;
        else if(i == 'S') y--;
        else if(i == 'W') x--;
        else x++;
    }


    if(abs(x) % 2 == 1 || abs(y) % 2 == 1) cout << "NO"<<endl;
    else if(n == 2 && x == 0 && y == 0) cout << "NO"<<endl;
    else{
        string ans = "";
        int north = 0, south = 0, west = 1, east = 1;
        char m[2] = {'R', 'H'};

        for(auto i : t){
            if(i == 'N') ans += m[north], north = 1 - north;
            else if (i == 'S') ans += m[south], south = 1 - south;
            else if (i == 'W') ans += m[west], west = 1 - west;
            else ans += m[east], east = 1 - east;
        }

        cout<<ans<<endl;
    }



}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}